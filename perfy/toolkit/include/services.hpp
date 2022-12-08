#include "generator.hpp"
#include <memory>

namespace toolkit {
	class GeneratorServices{
	public:
		GeneratorServices();
		~GeneratorServices();
		IGenerator* tcpGenerator() const;
		IGenerator* udpGenerator() const;
		IGenerator* icmpGenerator() const;
	private:
		struct Impl;
		std::unique_ptr<Impl> m_pImpl;
	};
}
