#-----------------------------------------------------------------------------
#
# IBIConfig.cmake - IBI CMake configuration file for external projects.
#
# This file is configured by IBI and used by the IBIUse.cmake module
# to load IBI's settings for an external project.

# The directory of IBIConfig.cmake is, by definition, IBI_DIR.
# (this_dir == IBI_DIR)
#
GET_FILENAME_COMPONENT(this_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
GET_FILENAME_COMPONENT(IBI_ROOT_DIR "${this_dir}/@IBI_CV_CONFIG_TO_ROOT@" ABSOLUTE)

# CMake files required to build client applications that use IBI.
SET(IBI_BUILD_SETTINGS_FILE "@IBI_CV_BUILD_SETTINGS_FILE@")
SET(IBI_USE_FILE "@IBI_CV_USE_FILE@")

# The IBI directories.
#SET(IBI_EXECUTABLE_DIRS "@IBI_CV_EXECUTABLE_DIRS@")
SET(IBI_LIBRARY_DIRS "@IBI_CV_LIBRARY_DIRS@")
SET(IBI_INCLUDE_DIRS "@IBI_CV_INCLUDE_DIRS@")
#SET(IBI_EXTRA_INCLUDE_DIRS "@IBI_CV_EXTRA_INCLUDE_DIRS@")

# The IBI libraries.
SET(IBI_LIBRARIES "@IBI_CV_BUILT_LIBRARIES@")
#SET(IBI_EXTRA_LIBRARY_DIRS "@IBI_CV_EXTRA_LIBRARY_DIRS@")

# The C flags added by IBI to the cmake-configured flags.
#SET(IBI_REQUIRED_C_FLAGS "@IBI_REQUIRED_C_FLAGS@")

# The IBI version number
SET(IBI_VERSION_MAJOR "@IBI_VERSION_MAJOR@")
SET(IBI_VERSION_MINOR "@IBI_VERSION_MINOR@")
SET(IBI_VERSION_PATCH "@IBI_VERSION_PATCH@")

# The IBI library dependencies.
IF(NOT IBI_NO_LIBRARY_DEPENDS)
  INCLUDE("@IBI_CV_LIBRARY_DEPENDS_FILE@")
ENDIF(NOT IBI_NO_LIBRARY_DEPENDS)
