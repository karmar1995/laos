#include "udp_generator.hpp"
#include "udp_socket.hpp"
#include <iostream>
#include "ping_controller.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::deadline_timer;


namespace toolkit {
namespace generators {

	class UdpPingListener : public IPingListener {
        public:
			
			struct info
			{
				size_t sent;
				size_t received;
			};

            void onPingBegin(const PingInfo&)
			{
				std::cout << "UDP ping begins" << std::endl;
			}

            void onPingSent(std::vector<char> buffer)
			{
				std::cout << "s\n"; 
				(void)buffer;
				m_info.sent++;
			}

            void onPingReceived(std::vector<char> buffer)
			{
				std::cout << "r\n"; 
				(void)buffer;
				m_info.received++;
			}

            void onPingEnd()
			{
				std::cout << "UDP ping ends" << std::endl;
			}

			const info& get_info() const
			{
				return m_info;
			}
		
		private:
			info m_info{};
        };


    class UdpPacketFactory : public IPacketFactory {
    public:
        std::vector<char> generateEchoPacket(size_t size)
		{
			return std::vector<char>(size, 0);
		}
    };

	struct UdpGenerator::Impl
	{

	};

	UdpGenerator::UdpGenerator() : m_pImpl(new Impl()) {}
	UdpGenerator::~UdpGenerator() = default;

	bool UdpGenerator::ping(const PingInfo& info)
	{
		UdpPingListener listener;
		UdpPacketFactory factory;
		UdpRawSocket socket(info.target, info.port);
		generators::PingController controller(factory, socket);

		controller.ping(info, listener);

		auto linfo = listener.get_info();

		std::cout << "UDP: pinging " << info.target
			<< " with interval: " << info.interval
			<< " with packet size: " << info.packetSize << " (" << linfo.sent + 8 << ')'
			<< std::endl;

		std::cout << "Received: " << linfo.received << std::endl;

		return true;
	}
}
}
