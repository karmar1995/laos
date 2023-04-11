#pragma once
#include "ping_controller.hpp"

namespace toolkit {

    class UdpPingListener : public generators::IPingListener {
    public:

        struct info {
            size_t sent;
            size_t received;
        };

        void onPingBegin(const PingInfo &) {
            std::cout << "UDP ping begins" << std::endl;
        }

        void onPingSent(std::vector<char> buffer) {
            std::cout << "s\n";
            (void) buffer;
            m_info.sent++;
        }

        void onPingReceived(std::vector<char> buffer) {
            std::cout << "r\n";
            (void) buffer;
            m_info.received++;
        }

        void onPingEnd() {
            std::cout << "UDP ping ends" << std::endl;
        }

        const info &get_info() const {
            return m_info;
        }

    private:
        info m_info{};
    };

}