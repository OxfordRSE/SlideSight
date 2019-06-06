cmake_minimum_required(VERSION 3.10)

project(SlideSight LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake"
                       ${CMAKE_MODULE_PATH})

# ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# export compiler flags for code completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Library dependencies

# OpenSlide
find_package(OpenSlide REQUIRED)
set(sight_include_dirs ${OPENSLIDE_INCLUDE_DIRS})
set(sight_libraries ${OPENSLIDE_LIBRARIES})

# std::filesystem
find_package(Filesystem REQUIRED COMPONENTS Experimental)


set(sight_source
  src/lib/SightLib.cpp
  src/lib/SlideData.cpp
  )

set(sight_headers
  src/lib/SightLib.hpp
  src/lib/SlideData.hpp
  )


set(sight_tests
  tests/TestSightLib.cpp
  tests/TestSlideData.cpp
  )
  
# the main SlideSight library and test suite
add_library(SightLib ${sight_source} ${sight_header})

target_include_directories(SightLib PUBLIC src/lib ${sight_include_dirs})
target_link_libraries(SightLib PUBLIC ${sight_libraries} filesystem)

enable_testing()

add_executable(TestSightLib ${sight_tests})
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
