cmake_minimum_required(VERSION 3.15)
project(cpp_versions)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(cpp_versions ${SOURCE_FILES})

add_subdirectory(cpp11)