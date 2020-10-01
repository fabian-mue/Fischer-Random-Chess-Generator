project(FischerGen)
cmake_minimum_required (VERSION 3.5)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(sources src/Generator.cpp src/main.cpp)

add_executable(FischerGen ${sources})


