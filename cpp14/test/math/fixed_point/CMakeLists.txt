cmake_minimum_required(VERSION 3.0.0)

project(test_math_fixed_point_1 VERSION 0.1.0)

set(CMAKE_CXX_CLANG_TIDY
	clang-tidy;
	-header-filter=.;
	-checks=*,-fuchsia-trailing-return,-llvm-header-guard,-*-braces-around-statements,-*-uppercase-literal-suffix,-*-explicit-conversions,-*-explicit-constructors;
)

set(SOURCE
	main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})
