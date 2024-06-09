cmake_minimum_required(VERSION 3.27)
project(PRO)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(PRO main.cpp
        Game.cpp
        Game.h
)

target_link_libraries(PRO sfml-graphics)
