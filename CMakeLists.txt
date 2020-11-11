cmake_minimum_required(VERSION 3.17)
project(inventory)

set(CMAKE_CXX_STANDARD 14)

add_executable(inventory test.cpp item.cpp item.h inventory.cpp inventory.h)