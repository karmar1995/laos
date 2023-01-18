cmake_minimum_required(VERSION 3.24.2)

project(toolkit
	VERSION 1.0
	DESCRIPTION "Perfy - network performance benchmark toolset"
	LANGUAGES CXX)

add_subdirectory(test)

add_library(toolkit SHARED
	src/generators/tcp_generator.cpp
	src/generators/udp_generator.cpp
	src/generators/icmp_generator.cpp
	src/generators/udp_socket.cpp
	src/services.cpp)

target_compile_definitions(toolkit PRIVATE BUILDING_TOOLKIT)

set(includes "./include")
set(generators "./src/generators")

include_directories(
		${includes}
		${generators})

target_compile_features(toolkit PRIVATE cxx_std_20)

install(TARGETS toolkit DESTINATION lib)


