#pragma once
#include <generator.h>
#include <memory>

namespace toolkit {
	namespace generators {

		class IcmpGenerator : public IGenerator
		{
		public:
			IcmpGenerator();
			~IcmpGenerator();
			bool ping(const PingInfo&) override;
		private:
			struct Impl;
			std::unique_ptr<Impl> m_pImpl;
		};
	}
}
