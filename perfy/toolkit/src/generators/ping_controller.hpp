#pragma once
#include <stdexcept>
#include <unistd.h>
#include <iostream>
#include <vector>
#include "irawsocket.hpp"
#include "generator.hpp"
#include "ipinglistener.hpp"

namespace toolkit {
    namespace generators{

        class IPacketFactory {
        public:
            virtual std::vector<char> generateEchoPacket(size_t size) = 0;
            virtual ~IPacketFactory() = default;
        };

        class PingController {
        public:
            PingController(IPacketFactory& factory, IRawSocket& rawSocket)
                : m_packetFactory(factory), 
                m_rawSocket(rawSocket)
            {

            }

            bool ping(const PingInfo& info, IPingListener& listener) {
                m_rawSocket.open(info.target, info.port);
                if(m_rawSocket.isOpen()){
                    listener.onPingBegin(info);
                    for(int i = 0; i < info.packetsNumber; i++ ){
                        std::vector<char> packet = m_packetFactory.generateEchoPacket(info.packetSize);
                        try
                        {
                            m_rawSocket.send(packet.data(), packet.size());
                        }
                        catch(const std::runtime_error& err)
                        {
                            std::cerr << "Error while sending message: " << err.what() << std::endl;
                        }

                        listener.onPingSent(packet);

                        char buff[256];
                        size_t received;
                        try
                        {
                            received = m_rawSocket.receive(&buff[0], 256);
                        }
                        catch(const std::runtime_error& err)
                        {
                            std::cerr << "Error while receiving message: " << err.what() << std::endl;
                        }

                        if(received == 0)
                        {
                            // TODO
                        }
                        
                        listener.onPingReceived({buff, buff+received});

                        sleep(info.interval); // usleep
                    }
                    listener.onPingEnd();
                    m_rawSocket.close();
                    return true;
                }
                return false;
            }


        protected:
            IPacketFactory& m_packetFactory;
            IRawSocket& m_rawSocket;
        };

    }
}