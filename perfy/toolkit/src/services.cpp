#include "services.h"
#include "tcp_generator.h"
#include "udp_generator.h"
#include "icmp_generator.h"

namespace toolkit {
	struct GeneratorServices::Impl{
		generators::TcpGenerator m_tcpGenerator;
		generators::UdpGenerator m_udpGenerator;
		generators::IcmpGenerator m_icmpGenerator;
	};

	GeneratorServices::GeneratorServices() : m_pImpl(new Impl) {}
	GeneratorServices::~GeneratorServices() = default;

	IGenerator* GeneratorServices::tcpGenerator() const {
		return &m_pImpl->m_tcpGenerator;
	}

	IGenerator* GeneratorServices::udpGenerator() const {
		return &m_pImpl->m_udpGenerator;
	}

	IGenerator* GeneratorServices::icmpGenerator() const {
		return &m_pImpl->m_icmpGenerator;
	}
}
