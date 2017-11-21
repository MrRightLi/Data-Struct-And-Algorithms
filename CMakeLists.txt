cmake_minimum_required(VERSION 3.8)
project(Link)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Stack.c)
add_executable(Link ${SOURCE_FILES})