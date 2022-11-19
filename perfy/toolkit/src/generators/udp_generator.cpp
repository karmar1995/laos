#include "udp_generator.h"
#include <iostream>

namespace toolkit {
	namespace generators{

	struct UdpGenerator::Impl{
	};

	UdpGenerator::UdpGenerator() : m_pImpl(new Impl()) {}
	UdpGenerator::~UdpGenerator() = default;

	bool UdpGenerator::ping(const PingInfo& info) {
		std::cout<<"UDP: pinging " << info.target
			<< " with interval: " << info.interval
			<< " with packet size: " << info.packetSize
			<< std::endl;
		return true;
	}
	}
}
