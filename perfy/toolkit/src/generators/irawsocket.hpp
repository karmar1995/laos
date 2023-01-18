#pragma once

#include <cstring>
#include <string>

namespace toolkit {
    namespace generators {

        enum EConnectionError {
            kOk,
            kCannotOpenSocket
        };

        class IRawSocket {
        public:
            virtual EConnectionError open(const std::string& targetIp, const std::string& port) = 0;
            virtual bool isOpen() const =0;
            virtual size_t send(char* buff, size_t len) = 0;
            virtual size_t receive(char* buff, size_t len) = 0;
            virtual void close() =0;
        };

    }
}