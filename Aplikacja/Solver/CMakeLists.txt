cmake_minimum_required(VERSION 3.12)
project(Solver)


set(CMAKE_CXX_STANDARD 17)
set(TEST_EXECUTABLE "SolverTests")
set(SOLVER_EXECUTABLE "Solver")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})


file(GLOB SRCS main.cpp
        sources/*.cpp
        sources/Definitions_and_Helpers/*.cpp
        sources/Functions/*.cpp
        sources/FunctionGetter/*.cpp
        sources/Logger/*.cpp
        sources/SymbolicOperations/*.cpp
        sources/Methods/*.cpp)

file(GLOB TESTS tests/*.cpp
        sources/*.cpp
        sources/Definitions_and_Helpers/*.cpp
        sources/Functions/*.cpp
        sources/FunctionGetter/*.cpp
        sources/Logger/*.cpp
        sources/SymbolicOperations/*.cpp
        sources/Methods/*.cpp)

add_executable(SolverTests ${TESTS})
add_executable(Solver ${SRCS})
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

target_include_directories(SolverTests PUBLIC
        include
        include/SymbolicOperations/headers
        tests)

target_include_directories(Solver PUBLIC
        include
        include/SymbolicOperations/headers
        )
if (GTEST_FOUND)
    target_include_directories(SolverTests PUBLIC ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})
endif ()
enable_testing()
target_link_libraries(SolverTests gtest gmock gtest_main pthread)
target_link_libraries(Solver pthread)
