#pragma once
#include "generator.hpp"
#include <vector>

namespace toolkit {
    namespace generators {

        class IPingListener {
        public:
            virtual void onPingBegin(const PingInfo &) = 0;
            virtual void onPingSent(std::vector<char> buffer) = 0;
            virtual void onPingReceived(std::vector<char> buffer) = 0;
            virtual void onPingEnd() = 0;

            ~IPingListener() = default;
        };
    }
}