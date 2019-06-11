cmake_minimum_required(VERSION 3.10)

project(SlideSight LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# export compiler flags for code completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


# Set global compiler warnings
if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-Wall -pedantic -Wextra -Werror)
endif()

# the main SlideSight library and test suite

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
        src/lib/Slide.hpp)

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
if (CXX_FILESYSTEM_IS_EXPERIMENTAL)
  target_compile_definitions(SightLib PUBLIC CXX_FILESYSTEM_IS_EXPERIMENTAL) 
endif()

enable_testing()

add_executable(TestSightLib ${sight_tests})
target_include_directories(TestSightLib PRIVATE tests)
target_link_libraries(TestSightLib PRIVATE SightLib filesystem)
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

    set(GUI_SOURCES src/gui/main.cpp src/gui/mainwindow.cpp src/gui/SlideView.cpp src/gui/SlideView.hpp src/gui/SlideModel.cpp src/gui/SlideModel.hpp)

    set(CPACK_PACKAGE_NAME "SlideSight")
    set(CPACK_PACKAGE_VERSION_MAJOR 1)
    set(CPACK_PACKAGE_VERSION_MINOR 0)
    set(CPACK_PACKAGE_VERSION_PATCH 0)
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "SlideSight")

    include(CPack)

    add_executable(SlideSight ${GUI_SOURCES})
    target_link_libraries(SlideSight Qt5::Core Qt5::Gui Qt5::Widgets SightLib filesystem)
endif (SlideSight_BUILD_GUI)

###################################
# Static analysis and other tools #
###################################

# Clang tidy as optional static analyzer
option(SlideSight_USE_CLANG_TIDY "Use clang tidy for static analysis" OFF)
if (SlideSight_USE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy" "clang-tidy-9" "clang-tidy-8" "clang-tidy-7"
            DOC "Path to clang-tidy executable")
    if(NOT CLANG_TIDY_EXE)
        message(STATUS "clang-tidy not found.")
    else()
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        set_target_properties(SightLib PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
endif()

# LLVM AddressSanitizer to detecting memory errors
# Note that there are many other sanitizers in LLVM to help detect errors, see
# http://travistoptips.blogspot.co.uk/2015/11/sanitize-all-things.html
option(SlideSight_MEMCHECK "Use LLVM AddressSanitizer to detecting memory errors" OFF)
if (SlideSight_MEMCHECK)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(STATUS "Configuring with LLVM AddressSanitizer")
        set(
                SlideSight_MEMCHECK_FLAGS
                -fno-optimize-sibling-calls
                -fsanitize=address
                -fsanitize-address-use-after-scope
        )
        target_compile_options(SightLib PUBLIC -O1 -g -fno-omit-frame-pointer ${SlideSight_MEMCHECK_FLAGS})
        target_link_libraries(SightLib PUBLIC -g ${SlideSight_MEMCHECK_FLAGS})
    else()
        message(FATAL_ERROR "clang compiler required with SlideSight_MEMCHECK: found ${CMAKE_CXX_COMPILER_ID}")
    endif()
endif()

# Setup coverage testing for GCC or Clang
option(SlideSight_ENABLE_COVERAGE "Enable coverage reporting for GCC or Clang" FALSE)
if (SlideSight_ENABLE_COVERAGE)
    if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
        message(STATUS "Configuring with coverage")
        target_compile_options(SightLib PUBLIC --coverage -O0)
        target_link_libraries(SightLib PUBLIC --coverage)
    else()
        message(FATAL_ERROR "GCC or Clang required with SlideSight_ENABLE_COVERAGE: found ${CMAKE_CXX_COMPILER_ID}")
    endif()
endif()
