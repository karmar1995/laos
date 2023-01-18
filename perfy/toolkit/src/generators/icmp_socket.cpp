#include "icmp_socket.hpp"

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::icmp;

namespace toolkit {
    namespace generators {
        IcmpSocket::IcmpSocket(const std::string &target, const std::string &service) : m_icmp_socket(io_service) {
            this->open(target, service);
        }

        EConnectionError IcmpSocket::open(const std::string &target, const std::string &service) {
            icmp::resolver::query i_query(target, "");
            icmp::resolver i_resolver(io_service);
            m_endpoint = i_resolver.resolve(i_query)->endpoint();
            boost::system::error_code err;
            this->close();

            if(m_icmp_socket.open(i_resolver.resolve(i_query)->endpoint().protocol(), err))
            {
                std::cerr << err.what() << std::endl;
                this->close();
                return kCannotOpenSocket;
            }

            if(!!m_icmp_socket.is_open())
            {
                std::cerr << err.what() << std::endl;
                this->close();
                return kCannotOpenSocket;
            }
            return kOk;
        }

        bool IcmpSocket::isOpen() const {return m_icmp_socket.is_open();}

        size_t IcmpSocket::send(char *buff, size_t len) {
            boost::system::error_code err;
            size_t sent = m_icmp_socket.send_to(boost::asio::buffer(buff, len), m_endpoint, 0, err);
            if(!sent)
            {
                throw std::runtime_error(err.what());
            }
            return sent;
        }

        size_t IcmpSocket::receive(char *buff, size_t len) {
            boost::system::error_code err;
            size_t received = m_icmp_socket.receive(boost::asio::buffer(buff, len), 0, err);
            if(!received)
            {
                throw std::runtime_error(err.what());
            }
            return received;
        }

        void IcmpSocket::close() {
            m_icmp_socket.close();
        }
    }
}