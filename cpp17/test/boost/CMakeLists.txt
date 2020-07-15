cmake_minimum_required(VERSION 3.9)
project(test_boost_raffer-static)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

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
	raffer/container/container.test.cpp
	raffer/logic/logic.test.cpp
	raffer/overload_set/overload_set.test.cpp
	raffer/regex/call/call.test.cpp
	raffer/regex/call/call_std.test.cpp
	raffer/switch/switch.test.cpp
	raffer/type/type.test.cpp
)

target_link_libraries(test_boost_raffer-static libraffer_regex_call-static.a)
target_link_libraries(test_boost_raffer-static libraffer_type-static.a)
