#include "udp_generator.hpp"
#include <boost/asio/ip/address_v4.hpp>
#include <iostream>
#include "ping_controller.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
// TODO: Replace with OS agnostic headers
#include <linux/udp.h>

using boost::asio::ip::icmp;
using boost::asio::ip::udp;
using boost::asio::deadline_timer;


namespace toolkit {
namespace generators {

	class UdpPingListener : IPingListener {
        public:
            void onPingBegin(const PingInfo&) override;
            void onPingSent(std::vector<char> buffer) override;
            void onPingReceived(std::vector<char> buffer) override;
            void onPingEnd() override;
            ~UdpPingListener();
		
		private:
			
        };


    class UdpPacketFactory : IPacketFactory {
    public:
        std::vector<char> generateEchoPacket(size_t size)
		{
			return std::vector<char>(size, 0);
		}

        ~UdpPacketFactory();
    };

	struct UdpGenerator::Impl
	{

	};

	UdpGenerator::UdpGenerator() : m_pImpl(new Impl()) {}
	UdpGenerator::~UdpGenerator() = default;

	bool UdpGenerator::ping(const PingInfo& info)
	{	
		// Ping payload
		std::vector<char> data(info.packetSize, 0);
		boost::asio::streambuf rcv_buffer;

		boost::asio::io_service io_service;
		icmp::socket icmp_socket(io_service);
		udp::socket udp_socket(io_service);
		udp::resolver resolver(io_service);
		icmp::resolver icmp_resolver(io_service);
		udp::resolver::query query(info.target, "1337");
		icmp::resolver::query icmp_query(info.target, "");

		udp::endpoint remote_endpoint(resolver.resolve(query)->endpoint());
		icmp::endpoint icmp_remote_endpoint(icmp_resolver.resolve(icmp_query)->endpoint());

		udp_socket.open(remote_endpoint.protocol());
		icmp_socket.open(icmp_remote_endpoint.protocol());

		// Send the ping
		boost::system::error_code err;
		size_t sent = udp_socket.send_to(boost::asio::buffer(data), remote_endpoint, 0, err);
		udp_socket.close();

		if(sent == 0)
		{
			std::cerr << "UDP: " << err.message() << std::endl;
			return false;
		}

		std::cout << "UDP: pinging " << info.target
			<< " with interval: " << info.interval
			<< " with packet size: " << info.packetSize << " (" << sent + sizeof(struct udphdr) << ')'
			<< std::endl;

		size_t received = icmp_socket.receive_from(rcv_buffer.prepare(65536), icmp_remote_endpoint);
		std::cout << "Received: " << received << std::endl;

		return true;
	}
}
}
