cmake_minimum_required(VERSION 4.1)
project(daysCalc)

set(CMAKE_CXX_STANDARD 20)

add_executable(daysCalc main.cpp
        date_ctls.h
        date_ctls.cpp)
