cmake_minimum_required(VERSION 3.15)
project(GolfSim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2 REQUIRED COMPONENTS graphics window system)

include_directories(include)

add_executable(GolfSim
    src/main.cpp
    src/Vector2.cpp
    src/Simulation.cpp
    src/ClubDatabase.cpp
    src/ClubInput.cpp
    src/Renderer.cpp
)

target_link_libraries(GolfSim PRIVATE sfml-graphics sfml-window sfml-system)