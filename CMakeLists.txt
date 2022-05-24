cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCE_FILES main.cpp)

add_definitions(-DSFML_STATIC)
add_executable(game main.cpp inc/headers/dino.hpp inc/headers/tree.hpp src/dino.cpp src/tree.cpp inc/headers/myHeaders.h
        inc/headers/assetManager.hpp inc/headers/app.hpp src/app.cpp inc/headers/game.hpp src/game.cpp src/random.cpp inc/headers/random.hpp
        inc/headers/stateMachine.hpp src/stateMachine.cpp inc/headers/menu.hpp src/menu.cpp)
include_directories(inc/headers/)
include_directories(/usr/local/include)


include_directories(${SFML_INCLUDE_DIRS})
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

file(COPY "inc" DESTINATION ".")