cmake_minimum_required(VERSION 3.21)
project(PngInjector)

set(CMAKE_CXX_STANDARD 17)

add_executable(PngInjector main.cpp CRC.cpp CRC.h)
