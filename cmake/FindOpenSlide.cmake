# A CMake find module for the OpenSlide microscopy file reader library.
# - Try to find the OpenSlide library
# http://openslide.org
# Define a path using OPENSLIDE_ROOT
# Once done this will define
#
#  OPENSLIDE_FOUND - system has h2lib
#  OPENSLIDE_INCLUDE_DIRS - the h2lib include directory
#  OPENSLIDE_LIBRARIES - Link these to use h2lib
#

find_path(OPENSLIDE_INCLUDE_DIRS openslide.h
            PATH_SUFFIXES openslide
            PATHS ${OPENSLIDE_ROOT} 
            )

find_library(OPENSLIDE_LIBRARIES openslide
            PATHS ${OPENSLIDE_ROOT} 
            )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Openslide DEFAULT_MSG 
  OPENSLIDE_LIBRARIES
  OPENSLIDE_INCLUDE_DIRS
  )

