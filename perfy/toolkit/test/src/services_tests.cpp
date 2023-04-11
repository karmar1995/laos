#define BOOST_TEST_MODULE ServicesTest
#include <boost/test/unit_test.hpp>

#include "services.hpp"
#include "udp_generator.hpp"
#include "fake_socket.hpp"
#include "fake_ping_listener.hpp"

struct Fixture {
	Fixture() {
		setup();
	}
	~Fixture() {
		teardown();
	}

	void setup() {
		/* perform setup for all tests in suite, no-op for now */
	}

	void teardown() {
		/* perform teardown for all tests in suite, no-op for now */
	}
};

toolkit::PingInfo defaultPingInfo()
{
    toolkit::PingInfo info;
    info.interval = 10;
    info.packetSize = 100;
    info.packetsNumber = 1;
    info.target = "192.168.1.1";
    return info;
}

BOOST_FIXTURE_TEST_SUITE(GeneratorServices, Fixture)

BOOST_AUTO_TEST_CASE(ReturnsGenerators)
{
	toolkit::GeneratorServices generatorServices;
	BOOST_CHECK(generatorServices.tcpGenerator() != nullptr);
	BOOST_CHECK(generatorServices.udpGenerator() != nullptr);
	BOOST_CHECK(generatorServices.icmpGenerator() != nullptr);
}

BOOST_AUTO_TEST_CASE(PingReturnsFalseWhenFailsToConnectToSocket)
{
    FakeSocket socket;
    socket.allowOpenSocket(false);
    FakePingListener listener;
    toolkit::generators::UdpGenerator generator(listener, socket);
    BOOST_CHECK(!generator.ping(defaultPingInfo()));
}

BOOST_AUTO_TEST_CASE(PingReturnsTrueWhenPingsSuccessfully)
{
    FakeSocket socket;
    FakePingListener listener;
    toolkit::generators::UdpGenerator generator(listener, socket);
    BOOST_CHECK(generator.ping(defaultPingInfo()));
}

BOOST_AUTO_TEST_CASE(PingListenerIsNotifiedWhenPingStarts)
{
    FakeSocket socket;
    FakePingListener listener;
    BOOST_CHECK_EQUAL(listener.lastPingInfo().target, "");
    toolkit::generators::UdpGenerator generator(listener, socket);
    BOOST_CHECK(generator.ping(defaultPingInfo()));
    BOOST_CHECK_EQUAL(listener.lastPingInfo().target, "192.168.1.1");
}

BOOST_AUTO_TEST_SUITE_END()
