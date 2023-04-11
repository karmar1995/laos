#pragma once
#include "irawsocket.hpp"

class FakeSocket : public toolkit::generators::IRawSocket {
    toolkit::generators::EConnectionError open(const std::string& target, const std::string& service) override;
    bool isOpen() const override;
    size_t send(char* buff, size_t len) override;
    size_t receive(char* buff, size_t len) override;
    void close() override;
public:
    void allowOpenSocket(bool allow) { m_allowOpenSocket = allow;}
protected:
    bool m_allowOpenSocket = true;
    bool m_isOpen = false;
};
