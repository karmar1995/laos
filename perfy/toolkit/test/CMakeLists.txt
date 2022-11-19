cmake_minimum_required(VERSION 3.24.2)

project(toolkit_test
	VERSION 1.0
	DESCRIPTION "Perfy toolkit tests"
	LANGUAGES CXX)

find_package(Boost 1.74 REQUIRED
       	COMPONENTS 
	unit_test_framework
)

add_executable(toolkit_test
	src/services_tests.cpp
	)

#message("boost unit test: ${Boost_LIBRARIES}")

target_link_libraries(toolkit_test 
	${Boost_LIBRARIES}
	toolkit
)

set(includes "../include")
set(generators "../src/generators")

include_directories(
		${includes}
		${generators})

target_compile_features(toolkit_test PRIVATE cxx_std_20)

install(TARGETS toolkit_test DESTINATION bin)


