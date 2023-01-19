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

	};

	UdpGenerator::UdpGenerator() : m_pImpl(new Impl()) {}
	UdpGenerator::~UdpGenerator() = default;

	bool UdpGenerator::ping(const PingInfo& info, IPingListener* listener)
	{
//		UdpPingListener listener;
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
