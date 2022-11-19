#pragma once
#include <generator.h>
#include <memory>

namespace toolkit {
	namespace generators {

		class UdpGenerator : public IGenerator
		{
		public:
			UdpGenerator();
			~UdpGenerator();
			bool ping(const PingInfo&) override;
		private:
			struct Impl;
			std::unique_ptr<Impl> m_pImpl;
		};
	}
}
