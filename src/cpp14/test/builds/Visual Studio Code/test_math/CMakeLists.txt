cmake_minimum_required(VERSION 3.0.0)

project(test_math VERSION 0.1.0)

set(CMAKE_CXX_CLANG_TIDY 
	clang-tidy;
	--checks=*,-fuchsia-trailing-return
)

set(SOURCE
	../../../test_math/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})
