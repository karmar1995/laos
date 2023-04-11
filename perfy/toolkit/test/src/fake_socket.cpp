#include "fake_socket.hpp"

toolkit::generators::EConnectionError FakeSocket::open(const std::string &target, const std::string &service) {
    if(m_allowOpenSocket){
        m_isOpen = true;
        return toolkit::generators::EConnectionError::kCannotOpenSocket;
    }
    return toolkit::generators::EConnectionError::kOk;
}

bool FakeSocket::isOpen() const {
    return m_isOpen;
}

size_t FakeSocket::send(char *buff, size_t len) {
    return 0;
}

size_t FakeSocket::receive(char *buff, size_t len) {
    return 0;
}

void FakeSocket::close() {

}
