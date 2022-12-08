#include <iostream>
#include "services.hpp"

int main(int argc, char** argv) {
	toolkit::GeneratorServices generators;

	if(generators.tcpGenerator()) {
		generators.tcpGenerator()->ping({ "192.168.1.1", "", 100, 1024 });
	}
	else {
		std::cout<<"Tcp generator not available"<<std::endl;
	}

	if(generators.udpGenerator()) {
		generators.udpGenerator()->ping({ "localhost", "", 10, 2048 });
	}
	else {
		std::cout<<"Udp generator not available"<<std::endl;
	}

	if(generators.icmpGenerator()) {
		generators.icmpGenerator()->ping({ "192.168.3.1", "", 30, 128 });
	}
	else {
		std::cout<<"Icmp generator not available"<<std::endl;
	}

}
