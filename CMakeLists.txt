cmake_minimum_required(VERSION 3.28)
project(game)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp
        interface/Level.hpp
        interface/Level.hpp
        interface/Functions.hpp
        logic/Attacker.hpp
        logic/Hero.hpp
        logic/Enemy.hpp
        logic/Dragon.hpp
        logic/GreenDragon.hpp
        logic/BlueDragon.hpp
        logic/RebDragon.hpp
        logic/BlackDragon.hpp)

target_link_libraries(game sfml-graphics)
