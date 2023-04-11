#pragma once
#include "ipinglistener.hpp"

class FakePingListener : public toolkit::generators::IPingListener
{
public:
    void onPingBegin(const toolkit::PingInfo &) override;
    void onPingSent(std::vector<char> buffer) override;
    void onPingReceived(std::vector<char> buffer) override;
    void onPingEnd() override;

    toolkit::PingInfo lastPingInfo() const;
protected:
    toolkit::PingInfo m_lastPingInfo;
};