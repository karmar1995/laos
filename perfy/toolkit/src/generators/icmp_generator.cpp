#include "icmp_generator.hpp"
#include <iostream>
#include "ping_controller.hpp"
#include "raw_socket.hpp"

namespace toolkit {
	namespace generators{
        class IcmpPingListener : public IPingListener {
        public:

            struct info
            {
                size_t sent;
                size_t received;
            };

            void onPingBegin(const PingInfo&)
            {
                std::cout << "ICMP ping begins" << std::endl;
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
                std::cout << "ICMP ping ends" << std::endl;
            }

            const info& get_info() const
            {
                return m_info;
            }

        private:
            info m_info{};
        };

        class IcmpPacketFactory : public IPacketFactory {
        public:
            std::vector<char> generateEchoPacket(size_t ) { return {}; };

        };

		struct IcmpGenerator::Impl{
            IcmpPingListener m_icmpListener;
            IcmpPacketFactory m_icmpFactory;
            IcmpRawSocket m_icmpRawSocket;
		};

		IcmpGenerator::IcmpGenerator() : m_pImpl(new Impl()) {}
		IcmpGenerator::~IcmpGenerator() = default;

		bool IcmpGenerator::ping(const PingInfo& info) {

            generators::PingController controller(m_pImpl->m_icmpFactory,
                                                  m_pImpl->m_icmpRawSocket);
            controller.ping(info, m_pImpl->m_icmpListener);

            auto listenerInfo = m_pImpl->m_icmpListener.get_info();
			std::cout<<"ICMP: pinging " << info.target
				<< " with interval: " << info.interval
				<< " with packet size: " << info.packetSize
				<< std::endl;

            std::cout<<"ICMP Received: " << listenerInfo.received << std::endl;
			return true;
		}
	}
}
