cmake_minimum_required(VERSION 3.9)
project(test_boost_raffer-static)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR_termux "/data/data/com.termux/files/usr/lib/boost_1_73_0")
set(Boost_INCLUDE_DIR_windows "C:/Program Files/boost/boost_1_73_0")
set(Raffer_INCLUDE_DIR "../../include")
include_directories(
	${Boost_INCLUDE_DIR_termux}
	${Boost_INCLUDE_DIR_windows}
	${Raffer_INCLUDE_DIR}
)
link_directories(
	../../build
)

add_executable(test_boost_raffer-static
	raffer/raffer.test.cpp
	raffer/math/math.test.cpp
	raffer/math/fixed_point/fixed_point.test.cpp
	raffer/math/fraction/fraction.test.cpp
	raffer/operators/arithmetic_operators.test.cpp
	raffer/operators/comparison_operators.test.cpp
)
