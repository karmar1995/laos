#pragma once
#include <string>

namespace toolkit {

	struct PingInfo {
		std::string target;			// ip or hostname of ping target
		std::string service = "";	// port for tcp/udp
		size_t count = 5;			// number of pings to send
		int interval = 0;			// interval between packets
		uint16_t packetSize = 0;	// packet size (bytes)
	};

	class IGenerator {
	public:
		virtual ~IGenerator() = default;
		virtual bool ping(const PingInfo&) = 0;
	};
}
