cmake_minimum_required(VERSION 3.20)
project(pb05)

set(CMAKE_CXX_STANDARD 14)

add_executable(pb05 main.cpp src/Produs.cpp headers/Produs.h src/Client.cpp headers/Client.h src/Casa.cpp headers/Casa.h src/ProduseClient.cpp headers/ProduseClient.h)
