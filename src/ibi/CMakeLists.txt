
# Parse sub dirs for sources
FILE (GLOB_RECURSE sources "*.cpp")
FILE (GLOB_RECURSE headers "*.h")
FILE (GLOB_RECURSE moc_headers "ibiQ*.h")

QT4_WRAP_CPP (moc_sources ${moc_headers})

SET (full_sources
    ${sources}
    ${headers}
    ${moc_sources}
)

# Compile main ibi library
ADD_LIBRARY (ibi SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi ${LIBS})