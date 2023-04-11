#include "udp_generator.hpp"
#include "udp_socket.hpp"
#include <iostream>
#include "ping_controller.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::deadline_timer;


namespace toolkit {
namespace generators {

    class UdpPacketFactory : public IPacketFactory {
    public:
        std::vector<char> generateEchoPacket(size_t size)
		{
			return std::vector<char>(size, 0);
		}
    };

	struct UdpGenerator::Impl
	{
        IPingListener& m_pingListener;
        IRawSocket& m_rawSocket;
        UdpPacketFactory m_packetFactory;

        Impl(IPingListener& listener, IRawSocket& socket)
        : m_pingListener(listener), m_rawSocket(socket)
        {

        }

        bool ping(const PingInfo& info){
            generators::PingController controller(m_packetFactory, m_rawSocket);
            /*
            auto linfo = listener.get_info();

            std::cout << "UDP: pinging " << info.target
                      << " with interval: " << info.interval
                      << " with packet size: " << info.packetSize << " (" << linfo.sent + 8 << ')'
                      << std::endl;

            std::cout << "Received: " << linfo.received << std::endl;
            */
            return controller.ping(info, m_pingListener);

        }
	};

	UdpGenerator::UdpGenerator(IPingListener& listener, IRawSocket& socket)
    : m_pImpl(new Impl(listener, socket))
    {

    }
	UdpGenerator::~UdpGenerator() = default;

	bool UdpGenerator::ping(const PingInfo& info)
	{
        return m_pImpl->ping(info);
		/*UdpPingListener listener;
		UdpPacketFactory factory;
		UdpRawSocket socket(info.target, info.port);*/
	}
}
}
