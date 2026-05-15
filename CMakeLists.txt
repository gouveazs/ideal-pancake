cmake_minimum_required(VERSION 3.16)

project(ideal_pancake
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(ideal_pancake
    src/main.cpp
    src/core/Game.cpp
    src/scenes/MainMenuScene.cpp
    src/scenes/InterrogationRoom.cpp
)

target_link_libraries(ideal_pancake
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
