#include "icmp_generator.h"
#include <iostream>
#include "ping_controller.hpp"
#include "raw_socket.hpp"

namespace toolkit {
	namespace generators{

        class IcmpPacketFactory : public IPacketFactory {
        public:
            std::vector<char> generateEchoPacket(size_t ) { return {}; };

        };

		struct IcmpGenerator::Impl{
            IcmpRawSocket m_icmpRawSocket;
            IcmpPacketFactory m_icmpFactory;

		};

		IcmpGenerator::IcmpGenerator() : m_pImpl(new Impl()) {}
		IcmpGenerator::~IcmpGenerator() = default;

		bool IcmpGenerator::ping(const PingInfo& info) {
            IPingListener* tmp = nullptr;
            generators::PingController controller(m_pImpl->m_icmpFactory,
                                                  m_pImpl->m_icmpRawSocket);
            controller.ping(info, *tmp);
			std::cout<<"ICMP: pinging " << info.target
				<< " with interval: " << info.interval
				<< " with packet size: " << info.packetSize
				<< std::endl;
			return true;
		}
	}
}
