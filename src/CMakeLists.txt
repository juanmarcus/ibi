
# Look for headers in current source dir
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Parse sub dirs for sources
FILE (GLOB_RECURSE sources "ibi*/*.cpp")
FILE (GLOB_RECURSE headers "ibi*/*.h")
FILE (GLOB_RECURSE moc_headers "ibi*/ibiQt*.h")

QT4_WRAP_CPP (moc_sources ${moc_headers})

SET (full_sources
    ${sources}
    ${headers}
    ${moc_sources}
)

# Compile main ibi library
ADD_LIBRARY (ibi SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi ${LIBS})

# Add our library to list of libraries
#LINK_DIRECTORIES (${IBI_LIBRARY_PATH})
#MESSAGE (STATUS "${IBI_LIBRARY_PATH}")
SET (LIBS ${LIBS} ibi)

# Build executables
ADD_SUBDIRECTORY (bin)