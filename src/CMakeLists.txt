
# Look for headers in ibi source dir
INCLUDE_DIRECTORIES(
    "${CMAKE_CURRENT_SOURCE_DIR}/ibi"
)

# Build library
ADD_SUBDIRECTORY (ibi)

# Add our library to list of libraries
SET (LIBS ${LIBS} ibi)

# Build plugins
ADD_SUBDIRECTORY (plugins)


# Build executables
ADD_SUBDIRECTORY (bin)