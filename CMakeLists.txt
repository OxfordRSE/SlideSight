cmake_minimum_required(VERSION 3.10)

project(SlideSight LANGUAGES CXX)

# ensure C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# export compiler flags for code completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# the main SlideSight library and test suite
add_library(SightLib src/lib/SightLib.cpp)

target_include_directories(SightLib PUBLIC src/lib)

enable_testing()

add_executable(TestSightLib tests/TestSightLib.cpp)
target_include_directories(TestSightLib PRIVATE tests)
target_link_libraries(TestSightLib PRIVATE SightLib)
add_test(TestSightLib TestSightLib)

# the main graphical executable
option(SlideSight_BUILD_GUI "Whether to build the main GUI" ON)
if (SlideSight_BUILD_GUI)
    find_package(Qt5Widgets CONFIG REQUIRED)
    find_package(Qt5Core CONFIG REQUIRED)
    find_package(Qt5Gui CONFIG REQUIRED)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)

    set(GUI_SOURCES src/gui/main.cpp src/gui/mainwindow.cpp src/gui/mainwindow.ui)

    set(CPACK_PACKAGE_NAME "SlideSight")
    set(CPACK_PACKAGE_VERSION_MAJOR 1)
    set(CPACK_PACKAGE_VERSION_MINOR 0)
    set(CPACK_PACKAGE_VERSION_PATCH 0)
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "SlideSight")

    include(CPack)

    add_executable(SlideSight ${GUI_SOURCES})
    target_link_libraries(SlideSight Qt5::Core Qt5::Gui Qt5::Widgets SightLib)
endif (SlideSight_BUILD_GUI)
