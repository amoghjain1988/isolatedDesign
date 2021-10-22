cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# This command attempts to find the library, REQUIRED argument is optional

project(hello VERSION 1.0)
add_executable(buildfile main.cpp)
find_package(PostgreSQL REQUIRED)
target_include_directories(buildfile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(buildfile PRIVATE PostgreSQL::PostgreSQL)
