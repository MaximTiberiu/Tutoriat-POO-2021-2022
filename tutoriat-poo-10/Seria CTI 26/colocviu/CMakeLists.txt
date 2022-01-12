cmake_minimum_required(VERSION 3.20)
project(colocviu)

set(CMAKE_CXX_STANDARD 14)

add_executable(colocviu main.cpp Companie.cpp Companie.h Zbor.cpp Zbor.h ZborLowCost.cpp ZborLowCost.h ZborLinie.cpp ZborLinie.h ZborCharter.cpp ZborCharter.h)
