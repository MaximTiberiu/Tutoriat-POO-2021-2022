cmake_minimum_required(VERSION 3.20)
project(p05)

set(CMAKE_CXX_STANDARD 14)

add_executable(p05 main.cpp src/Produs.cpp headers/Produs.h src/Client.cpp headers/Client.h)
