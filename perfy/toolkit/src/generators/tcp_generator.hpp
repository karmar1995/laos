#pragma once
#include <generator.hpp>
#include <memory>

namespace toolkit {
	namespace generators {

		class TcpGenerator : public IGenerator
		{
		public:
			TcpGenerator();
			~TcpGenerator();
			bool ping(const PingInfo&) override;
		private:
			struct Impl;
			std::unique_ptr<Impl> m_pImpl;
		};
	}
}
