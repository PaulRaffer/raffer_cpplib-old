cmake_minimum_required(VERSION 3.9)
project(boost_test)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 11)

set(Boost_INCLUDE_DIR "C:/Program Files/boost/boost_1_73_0")
set(Raffer_INCLUDE_DIR "../../include")
include_directories(
	${Boost_INCLUDE_DIR}
	${Raffer_INCLUDE_DIR}
)

add_executable(boost_test main.cpp)
