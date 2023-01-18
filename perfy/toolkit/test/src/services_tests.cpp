#define BOOST_TEST_MODULE ServicesTest
#include <boost/test/unit_test.hpp>

#include "services.hpp"

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

BOOST_FIXTURE_TEST_SUITE(GeneratorServices, Fixture)

BOOST_AUTO_TEST_CASE(ReturnsGenerators)
{
	toolkit::GeneratorServices generatorServices;
	BOOST_CHECK(generatorServices.tcpGenerator());
	BOOST_CHECK(generatorServices.udpGenerator());
	BOOST_CHECK(generatorServices.icmpGenerator());
}

BOOST_AUTO_TEST_SUITE_END()
