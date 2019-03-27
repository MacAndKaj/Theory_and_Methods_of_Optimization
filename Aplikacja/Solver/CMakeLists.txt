cmake_minimum_required(VERSION 3.12)
project(Solver)


set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_NAME "SolverTests")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(include)
file(GLOB SRCS
        sources/*.cpp
        sources/Functions/*.cpp
        sources/FunctionGetter/*.cpp
        sources/Logger/*.cpp
        tests/*.cpp)


add_executable(SolverTests ${SRCS} )

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
endif ()
enable_testing()
target_link_libraries(SolverTests gtest gmock gtest_main pthread)
