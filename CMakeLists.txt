cmake_minimum_required(VERSION 4.1)
project(PlantDynamicsSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlantDynamicsSimulator main.cpp
        chaos/ChaosGenerator.cpp
        chaos/ChaosGenerator.h
        weather/WeatherSystem.cpp
        weather/WeatherSystem.h
        weather/TimeSystem.cpp
        weather/TimeSystem.h)
