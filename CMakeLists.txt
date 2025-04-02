cmake_minimum_required(VERSION 3.30)
project(gokart)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES
        main.cpp
        src/model/guest/*.cpp
        src/model/kart/*.cpp
        src/model/map/*.cpp
        src/model/race/*.cpp
        src/model/staff/*.cpp
)

add_executable(gokart ${SOURCES})