cmake_minimum_required(VERSION 3.23)

include_directories( ${OPENGL_INCLUDE_DIRS} )

include_directories(glfw/include/)
include_directories(glad/glad/include/)

project(CGameEngine C)

set(CMAKE_C_STANDARD 99)

add_library(glad glad/glad/src/glad.c)

add_executable(CGameEngine main.c types.h shader.h)

target_link_libraries( CGameEngine ${OPENGL_LIBRARIES} glfw glad )