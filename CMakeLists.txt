cmake_minimum_required (VERSION 2.6) 
project (IBI)

#-----------------------------------------------------------------------------
# IBI version number.
SET(IBI_VERSION_MAJOR "0")
SET(IBI_VERSION_MINOR "1")
SET(IBI_VERSION_PATCH "0")

#-----------------------------------------------------------------------------
# Extra cmake stuff
SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

#-----------------------------------------------------------------------------
# Uninstall target
CONFIGURE_FILE (
  "${CMAKE_CURRENT_SOURCE_DIR}/CMake/cmake_uninstall.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/CMake/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET (uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/CMake/cmake_uninstall.cmake")

#-----------------------------------------------------------------------------
# Verbose makefile for helping eclise
SET (CMAKE_VERBOSE_MAKEFILE ON)

#-----------------------------------------------------------------------------
# Find required packages
find_package (Teem REQUIRED)
find_package (Qt4 REQUIRED)
find_package (Boost 1.39.0 COMPONENTS program_options REQUIRED)
find_package (QGLViewer REQUIRED)

#-----------------------------------------------------------------------------
# Use files
include (${Teem_USE_FILE})
set(QT_USE_QTOPENGL TRUE)
set(QT_USE_QTXML TRUE)
include (${QT_USE_FILE})

#-----------------------------------------------------------------------------
# Include directories
INCLUDE_DIRECTORIES (
    ${QGLVIEWER_INCLUDE_DIR}
)

#-----------------------------------------------------------------------------
# Definitions
ADD_DEFINITIONS(
    ${QGLVIEWER_DEFINITIONS}
)

#-----------------------------------------------------------------------------
# Save include directories
#set(EXTRA_INCLUDE_DIRS ${Teem_INCLUDE_DIRS} ${QT_INCLUDE_DIRS})

#-----------------------------------------------------------------------------
# Save library directories
#set(EXTRA_LIBRARY_DIRS ${Teem_LIBRARY_DIRS} ${QT_LIBRARY_DIRS})

#-----------------------------------------------------------------------------
# Configure libraries 
set(LIBS ${LIBS} ${Teem_LIBRARIES} ${QT_LIBRARIES} ${Boost_LIBRARIES} ${QGLVIEWER_LIBRARY})

#-----------------------------------------------------------------------------
# Configure destination dirs
SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib CACHE INTERNAL "Single output directory for building all libraries.")
MARK_AS_ADVANCED (LIBRARY_OUTPUT_PATH)
SET (IBI_LIBRARY_PATH "${LIBRARY_OUTPUT_PATH}")

#-----------------------------------------------------------------------------
# Dispatch the build into source subdirectory
ADD_SUBDIRECTORY (src)

#-----------------------------------------------------------------------------
# Prepare installation
#FOREACH (libname ${IBI_SUBLIBS})
#ENDFOREACH (libname ${IBI_SUBLIBS})

#-----------------------------------------------------------------------------
# Help outside projects build IBI projects.
INCLUDE (CMakeExportBuildSettings)
EXPORT_LIBRARY_DEPENDENCIES(${IBI_BINARY_DIR}/IBILibraryDepends.cmake)
CMAKE_EXPORT_BUILD_SETTINGS(${IBI_BINARY_DIR}/IBIBuildSettings.cmake)

# IBI_CV_ prefixed variables are only used inside IBIConfig.cmake.in for
# replacement during the following two CONFIGURE_FILE calls. One is for use
# from the build tree, one is for use from the install tree.


# For build tree usage

# In the build tree, IBIConfig.cmake is in IBI_BINARY_DIR. The root of the
# tree for finding include files relative to IBIConfig.cmake is "."
# 
SET(IBI_CV_CONFIG_TO_ROOT ".")
SET(IBI_CV_LIBRARY_DEPENDS_FILE ${IBI_BINARY_DIR}/IBILibraryDepends.cmake)
#SET(IBI_CV_EXECUTABLE_DIRS ${IBI_EXECUTABLE_DIRS})
#MESSAGE (STATUS "${IBI_LIBRARY_PATH}")
SET(IBI_CV_LIBRARY_DIRS ${LIBRARY_OUTPUT_PATH})
SET(IBI_CV_USE_FILE ${IBI_SOURCE_DIR}/CMake/IBIUse.cmake)
SET(IBI_CV_INCLUDE_DIRS "${IBI_SOURCE_DIR}/src/ibi")
SET(IBI_CV_BUILD_SETTINGS_FILE ${IBI_BINARY_DIR}/IBIBuildSettings.cmake)
SET(IBI_CV_BUILT_LIBRARIES ibi) # The libraries built by ibi.

CONFIGURE_FILE("${IBI_SOURCE_DIR}/CMake/IBIConfig.cmake"
  "${IBI_BINARY_DIR}/IBIConfig.cmake" @ONLY IMMEDIATE)


# For install tree usage

# In the install tree, TeemConfig.cmake is in lib or lib/Teem-X.Y based on the
# value of Teem_USE_LIB_INSTALL_SUBDIR. The root of the tree for finding
# include files relative to TeemConfig.cmake is therefore ".." or "../.."
# 
#IF(Teem_USE_LIB_INSTALL_SUBDIR)
#  SET(Teem_CV_CONFIG_TO_ROOT "../..")
#ELSE(Teem_USE_LIB_INSTALL_SUBDIR)
#  SET(Teem_CV_CONFIG_TO_ROOT "..")
#ENDIF(Teem_USE_LIB_INSTALL_SUBDIR)

#SET(Teem_CV_LIBRARY_DEPENDS_FILE "\${Teem_ROOT_DIR}/lib${EXTRA_INSTALL_PATH}/TeemLibraryDepends.cmake")
#SET(Teem_CV_EXECUTABLE_DIRS "\${Teem_ROOT_DIR}/bin")
#SET(Teem_CV_LIBRARY_DIRS "\${Teem_ROOT_DIR}/lib${EXTRA_INSTALL_PATH}")
#SET(Teem_CV_USE_FILE "\${Teem_ROOT_DIR}/lib${EXTRA_INSTALL_PATH}/TeemUse.cmake")
#SET(Teem_CV_INCLUDE_DIRS "\${Teem_ROOT_DIR}/include")
#SET(Teem_CV_BUILD_SETTINGS_FILE "\${Teem_ROOT_DIR}/lib${EXTRA_INSTALL_PATH}/TeemBuildSettings.cmake")
#SET(Teem_CV_BUILT_LIBRARIES teem) # The libraries built by teem.  Currently we only build the mega library.

#CONFIGURE_FILE("${Teem_SOURCE_DIR}/CMake/TeemConfig.cmake.in"
#  "${Teem_BINARY_DIR}/CMake/TeemConfig.cmake" @ONLY IMMEDIATE)


#INSTALL(FILES ${Teem_INSTALLED_HEADER_FILES}
#  DESTINATION include/teem
#  )

#INSTALL(FILES
#  "${Teem_BINARY_DIR}/CMake/TeemConfig.cmake"
#  "${Teem_SOURCE_DIR}/CMake/TeemUse.cmake"
#  "${Teem_BINARY_DIR}/TeemBuildSettings.cmake"
#  "${Teem_BINARY_DIR}/TeemLibraryDepends.cmake"
#  DESTINATION lib${EXTRA_INSTALL_PATH}
#  )
