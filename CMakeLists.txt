cmake_minimum_required(VERSION 3.10)

project(slidessight)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCES src/gui/main.cpp src/gui/mainwindow.cpp src/gui/mainwindow.ui)
set (CPACK_PACKAGE_NAME "SlideSight")
set (CPACK_PACKAGE_VERSION_MAJOR 1)
set (CPACK_PACKAGE_VERSION_MINOR 0)
set (CPACK_PACKAGE_VERSION_PATCH 0)
set (CPACK_PACKAGE_INSTALL_DIRECTORY "SlideSight")

include(CPack)

add_executable(SlideSight ${SOURCES})
target_link_libraries(SlideSight Qt5::Core Qt5::Gui Qt5::Widgets)

