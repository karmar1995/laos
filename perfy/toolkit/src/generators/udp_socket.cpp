#include <boost/asio.hpp>

#include "udp_socket.hpp"

using boost::asio::ip::udp;

namespace toolkit {
    namespace generators {

			EConnectionError UdpRawSocket::open(const std::string& target, const std::string& service)
			{
				udp::resolver::query query(target, service);
				udp::resolver resolver(io_service);

				m_socket.open(resolver.resolve(query)->endpoint().protocol());

				if(!m_socket.is_open())
				{
					return kCannotOpenSocket;
				}

				return kOk;
			}

            bool UdpRawSocket::isOpen() const
			{
				return m_socket.is_open();
			}

            size_t UdpRawSocket::send(char* buff, size_t len)
			{
				return m_socket.send(boost::asio::buffer(buff, len));
			}

            size_t UdpRawSocket::receive(char* buff, size_t len)
			{
				return m_socket.receive(boost::asio::buffer(buff, len));
			}

            void UdpRawSocket::close()
			{
				m_socket.close();
			}
	}
}
