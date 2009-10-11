
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Build sub libraries
FOREACH (subdir ${IBI_SUBLIBS})
    ADD_SUBDIRECTORY (${subdir})
ENDFOREACH (subdir ${IBI_SUBLIBS})

# Build executables
ADD_SUBDIRECTORY (bin)