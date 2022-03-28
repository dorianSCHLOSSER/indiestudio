cmake_minimum_required(VERSION 3.11)

set(CMAKE_BUILD_TYPE Release)

project(bomberman)

set(CMAKE_CXX_STANDARD 17)

include(cmake_modules/Findraylib.cmake)
include_directories(include)

set (SRCS app/main.cpp src/core.cpp src/game/game.cpp src/game/actor.cpp
    src/game/components/border.cpp src/game/components/grass.cpp src/game/components/wall.cpp src/game/components/brick.cpp
    src/game/components/bomb.cpp src/game/components/bigBomb.cpp src/game/components/bonusBomb.cpp src/game/components/bonusLife.cpp)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} raylib)