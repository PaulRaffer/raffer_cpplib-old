cmake_minimum_required(VERSION 3.9)
project(raffer_cpplib)

set(CMAKE_CXX_STANDARD 11)

add_library(raffer_finally-static STATIC include/raffer/finally/finally.cpp include/raffer/finally/finally.hpp)
add_library(raffer_finally-shared SHARED include/raffer/finally/finally.cpp include/raffer/finally/finally.hpp)

add_library(raffer_system-static STATIC include/raffer/system/system.cpp include/raffer/system/system.hpp)
add_library(raffer_system-shared SHARED include/raffer/system/system.cpp include/raffer/system/system.hpp)
