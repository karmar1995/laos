#include <boost/asio.hpp>
#include <stdexcept>
#include <iostream>

#include "udp_socket.hpp"

using boost::asio::ip::udp;
using boost::asio::ip::icmp;

namespace toolkit {
    namespace generators {

			UdpRawSocket::UdpRawSocket(const std::string& target, const std::string& service)
				: m_udp_socket{io_service},
				m_icmp_socket{io_service}
			{
			}

			EConnectionError UdpRawSocket::open(const std::string& target, const std::string& service)
			{
                try {
                    udp::resolver::query u_query(target, service);
                    udp::resolver u_resolver(io_service);

                    icmp::resolver::query i_query(target, "");
                    icmp::resolver i_resolver(io_service);

                    boost::system::error_code err;
                    m_endpoint = u_resolver.resolve(u_query)->endpoint();
                    if (m_udp_socket.open(u_resolver.resolve(u_query)->endpoint().protocol(), err)) {
                        std::cerr << err.message() << std::endl;
                        this->close();
                        return kCannotOpenSocket;
                    }
                    if (m_icmp_socket.open(i_resolver.resolve(i_query)->endpoint().protocol(), err)) {
                        std::cerr << err.message() << std::endl;
                        this->close();
                        return kCannotOpenSocket;
                    }
                    if(!m_udp_socket.is_open() || !m_icmp_socket.is_open())
                    {
                        std::cerr << err.message() << std::endl;
                        this->close();
                        return kCannotOpenSocket;
                    }

                }
                catch(...) {
                    std::cout<<"Open failed"<<std::endl;
                    return kCannotOpenSocket;

                }

				return kOk;
			}

            bool UdpRawSocket::isOpen() const
			{
				return m_udp_socket.is_open() && m_icmp_socket.is_open();
			}

            size_t UdpRawSocket::send(char* buff, size_t len)
			{
				boost::system::error_code err;
				size_t sent = m_udp_socket.send_to(boost::asio::buffer(buff, len), m_endpoint, 0, err);

				if(sent == 0)
				{
					throw std::runtime_error(err.message());
				}

				return sent;
			}

            size_t UdpRawSocket::receive(char* buff, size_t len)
			{
				boost::system::error_code err;
				size_t received = m_icmp_socket.receive(boost::asio::buffer(buff, len), 0, err);

				if(received == 0)
				{
					throw std::runtime_error(err.message());
				}

				return received;
			}

            void UdpRawSocket::close()
			{
				m_udp_socket.close();
				m_icmp_socket.close();
			}
	}
}
