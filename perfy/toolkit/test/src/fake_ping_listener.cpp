//
// Created by kmarszal on 4/11/23.
//

#include "fake_ping_listener.hpp"

void FakePingListener::onPingBegin(const toolkit::PingInfo & info) {
    m_lastPingInfo = info;
}

void FakePingListener::onPingSent(std::vector<char> buffer) {

}

void FakePingListener::onPingReceived(std::vector<char> buffer) {

}

void FakePingListener::onPingEnd() {

}

toolkit::PingInfo FakePingListener::lastPingInfo() const {
    return m_lastPingInfo;
}
