#pragma once
#include "irawsocket.hpp"

namespace toolkit {
    namespace generators {

        class IcmpRawSocket : public IRawSocket {
            virtual EConnectionError open(const std::string& target, const std::string& service) override{}
            virtual bool isOpen() const override{}
            virtual size_t send(char* buff, size_t len) override{}
            virtual size_t receive(char* buff, size_t len) override{}
            virtual void close() override{}
        };

        class TcpRawSocket : public IRawSocket{

        };

    }
}