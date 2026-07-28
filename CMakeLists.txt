cmake_minimum_required(VERSION 3.20)

project(
    LANChatApplication
    VERSION 1.0.0
    DESCRIPTION "LAN Multi-Client Chat Application"
    LANGUAGES CXX
)

# C++ Standard

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Subprojects

add_subdirectory(common)
add_subdirectory(infrastructure)
add_subdirectory(server)
add_subdirectory(client)