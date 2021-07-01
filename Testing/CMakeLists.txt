cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

add_definitions("-DMUSIC_WAV")

set(CMAKE_CURRENT_BINARY_DIR ./build)
set(CMAKE_CURRENT_SOURCE_DIR .)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(SDL2_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Libraries/SDL)


project(testlinalg)

add_subdirectory(${SDL2_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/sdl)

add_executable(testlinalg ../Math/Line.cpp ../Math/Line.h ../Math/Matrix.cpp ../Math/Matrix.h ../Math/Vector3.h ../Math/Vector3.cpp ../Objects/Transform.cpp ../Objects/Transform.h ../Objects/SpaceShip.cpp ../Objects/SpaceShip.h ../Objects/Camera.cpp ../Objects/Camera.h ../Objects/Enemy.cpp ../Objects/Enemy.h ../Objects/Bullet.cpp ../Objects/Bullet.h ../Objects/AABB.cpp ../Objects/AABB.h catch_amalgamated.cpp catch_amalgamated.hpp Example.cpp )

target_link_libraries(testlinalg SDL2)

target_include_directories(testlinalg PUBLIC
        ${SDL2_SOURCE_DIR}/include
        ${SDL2_MIXER_SOURCE_DIR}/include
        ${SDL2IMAGE_SOURCE_DIR}
        ${SDL2TTF_SOURCE_DIR})



