cmake_minimum_required(VERSION 3.12)
project(Theory_And_Methods_of_Optimization)


set(CMAKE_CXX_STANDARD 17)
set(MAIN_EXECUTABLE "Optimization")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(Qt5DataVisualization_DIR "/home/maciek/Qt/5.11.2/gcc_64/lib/cmake/Qt5DataVisualization")
set(Qt5Core_DIR "/home/maciek/Qt/5.11.2/gcc_64/lib/cmake/Qt5Core")
set(Qt5Widgets_DIR "/home/maciek/Qt/5.11.2/gcc_64/lib/cmake/Qt5Widgets")
set(Qt5Gui_DIR "/home/maciek/Qt/5.11.2/gcc_64/lib/cmake/Qt5Gui")
set(Solver Solver)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS Polak_Ribiere/forms)
set(CMAKE_AUTOUIC)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Core Widgets Gui DataVisualization CONFIG REQUIRED)
set(AUTOGEN_BUILD_DIR Polak_Ribiere/forms)

file(GLOB MOC_UIC
        Polak_Ribiere/forms/*.ui)
file(GLOB MOC_HEADER
        Polak_Ribiere/include/*.h)

qt5_wrap_cpp(HEADERS ${MOC_HEADER})
qt5_wrap_ui(UIS  ${MOC_UIC})

file(GLOB SRCS
        Polak_Ribiere/main.cpp
        Polak_Ribiere/sources/*.cpp
        Polak_Ribiere/forms/*.cpp
        Polak_Ribiere/forms/*.ui
        Polak_Ribiere/include/*.cpp
        Solver/sources/*.cpp
        Solver/sources/Definitions_and_Helpers/*.cpp
        Solver/sources/Functions/*.cpp
        Solver/sources/FunctionGetter/*.cpp
        Solver/sources/Logger/*.cpp
        Solver/sources/SymbolicOperations/*.cpp
        Solver/sources/Methods/*.cpp)

add_definitions(${QT_DEFINITIONS})

add_library(MOCS ${HEADERS} ${UIS})
qt5_use_modules(MOCS Widgets)
add_executable(Optimization ${SRCS} Polak_Ribiere/qrc_images.cpp)

find_package(Threads REQUIRED)


include_directories(Solver/include
        ${AUTOGEN_BUILD_DIR}
        Polak_Ribiere/include
        Polak_Ribiere/include/forms
        )

target_link_libraries(Optimization
        pthread
        MOCS)
qt5_add_resources(Polak_Ribiere/images.qrc)
qt5_use_modules(Optimization Core Widgets DataVisualization Gui )
