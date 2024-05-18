cmake_minimum_required(VERSION 3.5)
project(Shambles)

# Building
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Common settings
set(CMAKE_CC_COMPILER gcc)
set(CMAKE_CC_STANDARD 17)
set(CMAKE_CC_FLAGS "-Wall -Wpedantic -Wextra ")
set(CMAKE_CC_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -fsanitize=address -O0 -g")
set(CMAKE_CC_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -s")


# Find OpenGL package
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# dependencies
add_subdirectory(external/GLFW)  


# Executable sources
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/main.c 
    ${CMAKE_SOURCE_DIR}/src/shamEngine/ui/ui.c 
    ${CMAKE_SOURCE_DIR}/src/shamEngine/shader/shader.c 
    # external
    ${CMAKE_SOURCE_DIR}/external/GLAD/src/glad.c
    )


# Executable
add_executable(Shambles ${SOURCES})

# Includes
target_include_directories(Shambles PRIVATE 
    ${CMAKE_SOURCE_DIR}/external/GLAD/include/ 
    ${CMAKE_SOURCE_DIR}/external/GLFW/include/ 
    ${CMAKE_SOURCE_DIR}/src/
    ${CMAKE_SOURCE_DIR}/src/core/
    )

# Link GLFW and OpenGL
target_link_libraries(Shambles PRIVATE glfw OpenGL::GL)
