cmake_minimum_required(VERSION 4.1)
project(PlantDynamicsSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlantDynamicsSimulator main.cpp
        chaos/ChaosGenerator.cpp
        chaos/ChaosGenerator.h
        weather/Weather.cpp
        weather/Weather.h
        weather/Time.cpp
        weather/Time.h
        weather/Climate.cpp
        weather/Climate.h
        service/FileWriter.cpp
        service/FileWriter.h
        service/FileReader.cpp
        service/FileReader.h
        manager/Simulator.cpp
        manager/Simulator.h
)
