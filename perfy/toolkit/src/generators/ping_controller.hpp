#include <vector>
#include "irawsocket.hpp"
#include "generator.h"

namespace toolkit {
    namespace generators{

        class IPingListener {
        public:
            virtual void onPingBegin(const PingInfo&) = 0;
            virtual void onPingSent(std::vector<char> buffer) = 0;
            virtual void onPingReceived(std::vector<char> buffer) = 0;
            virtual void onPingEnd() = 0;
            ~IPingListener() = default;
        };

        class IPacketFactory {
        public:
            virtual std::vector<char> generateEchoPacket(size_t size) = 0;
            virtual ~IPacketFactory() = default;
        };

        class PingController {
        public:
            PingController(IPacketFactory& factory, IRawSocket& rawSocket)
            : m_rawSocket(rawSocket)
            , m_packetFactory(factory)
            {}

            void ping(const PingInfo& info, IPingListener& listener) {
                m_rawSocket.open(info.target, 0);
                listener.onPingBegin(info);
                if(m_rawSocket.isOpen()){
                    for(int i = 0; i < info.packetsNumber; i++ ){
                        std::vector<char> packet = m_packetFactory.generateEchoPacket(info.packetSize);
                        m_rawSocket.send(packet.data(), packet.size());
                        listener.onPingSent(packet);

                        char buff[256] = {0};
                        m_rawSocket.receive(&buff[0], 256);
                        //listener.onPingReceived({buff, 256});

                        sleep(info.interval);

                    }
                }
                listener.onPingEnd();
                m_rawSocket.close();
            }


        protected:
            IPacketFactory& m_packetFactory;
            IRawSocket& m_rawSocket;
        };

    }
}