#include "services.h"
#include "tcp_generator.hpp"
#include "udp_generator.hpp"
#include "icmp_generator.hpp"

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
