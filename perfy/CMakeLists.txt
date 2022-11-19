cmake_minimum_required(VERSION 3.24.2)

project(perfy
	VERSION 1.0
	DESCRIPTION "Perfy - network performance benchmark toolset"
	LANGUAGES CXX)

find_package(Boost 1.74 REQUIRED
	COMPONENTS unit_test_framework)

include_directories(${BOOST_INCLUDE_DIRS})

#message("boost lib: ${Boost_LIBRARIES}")
#message("boost inc: ${Boost_INCLUDE_DIR}")

set(CMAKE_INSTALL_PREFIX "../install")

set(CMAKE_INSTALL_RPATH "${PROJECT_BINARY_DIR}/../install/lib")

add_executable(perfy
	src/main.cpp)

add_subdirectory(toolkit)

target_include_directories(perfy PUBLIC 
	"$(PROJECT_BINARY_DIR)"
	"$(PROJECT_SOURCE_DIR)/toolkit/include")

target_link_directories(perfy PUBLIC ${CMAKE_INSTALL_RPATH})

target_link_libraries(perfy PUBLIC toolkit)

target_compile_features(perfy PRIVATE cxx_std_20)

install(TARGETS perfy DESTINATION bin)
