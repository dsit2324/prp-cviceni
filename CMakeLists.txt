cmake_minimum_required(VERSION 4.0)
project(prp_pisemka)

set(CMAKE_CXX_STANDARD 20)

add_executable(prp_pisemka main.cpp
        Datum.cpp
        Datum.h)
