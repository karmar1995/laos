#include "tcp_generator.h"
#include <boost/asio/this_coro.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/basic_raw_socket.hpp>
#include <boost/asio/system_executor.hpp>

#include <iostream>

namespace toolkit {
	namespace generators{

		struct TcpGenerator::Impl{
		};

		TcpGenerator::TcpGenerator() : m_pImpl(new Impl()) {}
		TcpGenerator::~TcpGenerator() = default;

		bool TcpGenerator::ping(const PingInfo& info) {
			std::cout<<"TCP: pinging " << info.target
				<< " with interval: " << info.interval
				<< " with packet size: " << info.packetSize
				<< std::endl; 

			return true;
		}
	}
}
