cmake_minimum_required(VERSION 3.30)
project(gokart)

set(CMAKE_CXX_STANDARD 20)

add_executable(gokart main.cpp src/model/guest/Guest.cpp src/model/guest/AdultGuest.cpp src/model/guest/ChildGuest.cpp
        src/model/kart/GoKart.cpp src/model/kart/SmallGoKart.cpp src/model/kart/BigGokart.cpp src/model/kart/RaceGokart.cpp src/model/map/Map.cpp
        src/model/map/BeginnerMap.cpp src/model/map/IntermediateMap.cpp src/model/map/ProMap.cpp src/model/race/Race.cpp src/model/staff/TrackLead.cpp)
