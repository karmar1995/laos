#pragma once

#include "irawsocket.hpp"

#include <boost/asio.hpp>
namespace toolkit {
    namespace generators {
        class IcmpSocket : public IRawSocket {
        public:
            IcmpSocket(const std::string& target, const std::string& service);
            EConnectionError open(const std::string& target, const std::string& service) override;
            bool isOpen() const override;
            size_t send(char* buff, size_t len) override;
            size_t receive(char* buff, size_t len) override;
            void close() override;

        private:
            boost::asio::io_service io_service;
            boost::asio::ip::icmp::socket m_icmp_socket;
            boost::asio::ip::icmp::endpoint m_endpoint;
        };
    }
}
