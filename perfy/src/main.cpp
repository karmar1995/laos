#include <iostream>
#include "perfy_ui.hpp"

int main(int argc, char** argv) {
    PerfyUi ui(argc, argv);
    ui.start();
//	toolkit::GeneratorServices generators;
//
//	if(generators.tcpGenerator()) {
//		generators.tcpGenerator()->ping({ "192.168.1.1", 100, 1024 });
//	}
//	else {
//		std::cout<<"Tcp generator not available"<<std::endl;
//	}
//
//	if(generators.udpGenerator()) {
//		generators.udpGenerator()->ping({ "10.152.128.1", 10, 2048, 2 });
//	}
//	else {
//		std::cout<<"Udp generator not available"<<std::endl;
//	}
//
//	/*if(generators.icmpGenerator()) {
//		generators.icmpGenerator()->ping({ "192.168.3.1", 30, 128 });
//	}
//	else {
//		std::cout<<"Icmp generator not available"<<std::endl;
//	}*/
//
}
