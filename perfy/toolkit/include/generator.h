#pragma once
#include <string>

namespace toolkit {

	struct PingInfo {
		std::string target;	// ip or hostname of ping target
		int interval = 0;	// interval between packets
		int packetSize = 0;	// packet size, in bytes
		// in_port_t = 0; // port for tcp/udp
	};

	class IGenerator {
	public:
		virtual ~IGenerator() = default;
		virtual bool ping(const PingInfo&) = 0;
	};
}
