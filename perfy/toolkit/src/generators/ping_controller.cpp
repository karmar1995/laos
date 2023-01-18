#include "ping_controller.hpp"

namespace toolkit {
    namespace generators{

        class UdpPingListener : IPingListener 
        {
            void UdpPingListener::onPingBegin(const PingInfo&)
            {

            }
            void UdpPingListener::onPingSent(std::vector<char> buffer)
            {

            }
            void UdpPingListener::onPingReceived(std::vector<char> buffer)
            {

            }
            void UdpPingListener::onPingEnd() 


            }
        };

        class UdpPacketFactory : IPacketFactory 
        {
            std::vector<char> UdpPacketFactory::generateEchoPacket(size_t size)
            {

            }

        };

        
	}
}

