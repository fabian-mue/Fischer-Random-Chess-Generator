project(FischerGen)
cmake_minimum_required (VERSION 3.6)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(sources src/Generator.cpp src/Board.cpp src/main.cpp)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


