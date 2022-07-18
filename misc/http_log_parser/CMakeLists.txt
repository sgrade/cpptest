cmake_minimum_required(VERSION 3.18)
project(logmon 
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "HTTP log monitoring console program."
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(logmon main.cpp)

enable_testing()

add_executable(tester tester.cpp)
add_test(Tester tester)
