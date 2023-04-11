#pragma once
#include <generator.hpp>
#include <memory>


namespace toolkit {
	namespace generators {
        class IPingListener;
        class IRawSocket;

		class UdpGenerator : public IGenerator
		{
		public:
			UdpGenerator(IPingListener&, IRawSocket&);
			~UdpGenerator();
			bool ping(const PingInfo&) override;
		private:
			struct Impl;
			std::unique_ptr<Impl> m_pImpl;
		};
	}
}
