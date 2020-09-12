cmake_minimum_required(VERSION 3.9)
project(raffer_cpplib)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

add_library(raffer_regex_call-static STATIC include/raffer/regex/call/call.cpp include/raffer/regex/call/call.hpp)
add_library(raffer_regex_call-shared SHARED include/raffer/regex/call/call.cpp include/raffer/regex/call/call.hpp)

add_library(raffer_type-static STATIC include/raffer/type/type.cpp include/raffer/type/type.hpp)
add_library(raffer_type-shared SHARED include/raffer/type/type.cpp include/raffer/type/type.hpp)
