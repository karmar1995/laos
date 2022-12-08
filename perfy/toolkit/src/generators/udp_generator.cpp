#include "udp_generator.hpp"
#include <boost/asio/ip/address_v4.hpp>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
// TODO: Replace with OS agnostic headers
#include <linux/udp.h>

using boost::asio::ip::icmp;
using boost::asio::ip::udp;
using boost::asio::ip::address;
using boost::asio::deadline_timer;
namespace posix_time = boost::posix_time;

namespace toolkit {
namespace generators {

	struct UdpGenerator::Impl
	{

	};

	UdpGenerator::UdpGenerator() : m_pImpl(new Impl()) {}
	UdpGenerator::~UdpGenerator() = default;

	/**
	 *	@brief	High-level function that sends UDP pings with parameters specified in the argument
	 *	@returns	true when the target replies within a specified interval, otherwise false
	 */
	bool UdpGenerator::ping(const PingInfo& info)
	{
		return true;
	}

} // namespace generators
} // namespace toolkit