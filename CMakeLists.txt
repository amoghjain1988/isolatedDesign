cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# This command attempts to find the library, REQUIRED argument is optional

# find_package(PostgreSQL REQUIRED)


project(main VERSION 1.0)
add_executable(buildfile main.cpp)
target_include_directories(buildfile PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# target_include_directories(buildfile PRIVATE ${PostgreSQL_INCLUDE_DIRS})
# target_link_libraries(buildfile PRIVATE PostgreSQL::PostgreSQL)
