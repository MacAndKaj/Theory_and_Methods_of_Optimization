cmake_minimum_required(VERSION 3.12)
project(Theory_And_Methods_of_Optimization)


set(CMAKE_CXX_STANDARD 17)
set(MAIN_EXECUTABLE "Optimization")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(QtApp Polak_Ribiere)
set(Solver Solver)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB UIS
        QtApp/forms/*ui)

file(GLOB SRCS
        QtApp/sources/*.cpp
        Solver/sources/*.cpp
        Solver/sources/Definitions_and_Helpers/*.cpp
        Solver/sources/Functions/*.cpp
        Solver/sources/FunctionGetter/*.cpp
        Solver/sources/Logger/*.cpp
        Solver/sources/SymbolicOperations/*.cpp
        Solver/sources/Methods/*.cpp)


add_executable(Optimization ${SRCS})
find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui DataVisualization CONFIG REQUIRED)


include_directories(Optimization PUBLIC
        Solver
        QtApp/include
        )

target_link_libraries(Optimization
        pthread)
qt5_use_modules(Optimization Core Widgets DataVisualization Gui)
