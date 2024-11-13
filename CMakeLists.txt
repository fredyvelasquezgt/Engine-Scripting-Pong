cmake_minimum_required(VERSION 3.10)
project(PongGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(sol2 REQUIRED)
find_package(entt REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SOL2_INCLUDE_DIRS} ${ENTT_INCLUDE_DIRS})

add_executable(PongGame src/main.cpp src/Game.cpp src/Game.h src/Paddle.cpp src/Paddle.h src/Ball.cpp src/Ball.h
                       src/System/RenderSystem.cpp src/System/RenderSystem.h src/System/MovementSystem.cpp src/System/MovementSystem.h
                       src/Scripting/LuaBindings.cpp src/Scripting/LuaBindings.h)

target_link_libraries(PongGame ${SDL2_LIBRARIES} sol2::sol2 entt)
