#include "perfy_ui.hpp"
#include "../include/perfy_ui.hpp"
#include "toolkit/include/service.hpp"

class UdpPingListener : public IPingListener {
public:

    struct info
    {
        size_t sent;
        size_t received;
    };

    void onPingBegin(const PingInfo&)
    {
        std::cout << "UDP ping begins" << std::endl;
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
        std::cout << "UDP ping ends" << std::endl;
    }

    const info& get_info() const
    {
        return m_info;
    }

private:
    info m_info{};
};



struct Impl {
    toolkit::Services services;

    void pingUdp(std::string ip, std::string port) {
        UdpPingListener listener;
        services.generators()->ping({ip, port}, &listener);
    }
};

PerfyUi::PerfyUi() {

}

void PerfyUi::start() {
    //#todo: parse argv, use it to drive use cases with services
    //if(parser.startPingUdp()) {
    // impl->pingUdp(ip, port);
    //}
}
