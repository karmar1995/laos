#pragma once
#include "irawsocket.hpp"

namespace toolkit {
    namespace generators {

        class IcmpRawSocket : public IRawSocket {
            virtual EConnectionError open(const std::string& targetIp, const std::string& port) override{}
            virtual bool isOpen() const override{}
            virtual size_t send(char* buff, size_t len) override{}
            virtual size_t receive(char* buff, size_t len) override{}
            virtual void close() override{}
        };

        class UdpRawSocket : public IRawSocket{

        };

        class TcpRawSocket : public IRawSocket{

        };

    }
}