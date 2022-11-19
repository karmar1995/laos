#include "icmp_generator.h"
#include <iostream>

namespace toolkit {
	namespace generators{

		struct IcmpGenerator::Impl{
		};

		IcmpGenerator::IcmpGenerator() : m_pImpl(new Impl()) {}
		IcmpGenerator::~IcmpGenerator() = default;

		bool IcmpGenerator::ping(const PingInfo& info) {
			std::cout<<"ICMP: pinging " << info.target
				<< " with interval: " << info.interval
				<< " with packet size: " << info.packetSize
				<< std::endl;
			return true;
		}
	}
}
