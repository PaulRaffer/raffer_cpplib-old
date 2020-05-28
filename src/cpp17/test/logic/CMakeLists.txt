cmake_minimum_required(VERSION 3.0.0)

project(test_logic VERSION 0.1.0)

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -header-filter=.;
    -checks=*,-fuchsia-trailing-return,-llvm-header-guard,-*-braces-around-statements,-*-uppercase-literal-suffix;
)

set(SOURCE
    main.cpp
)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${SOURCE})

exec_program(${PROJECT_NAME})

