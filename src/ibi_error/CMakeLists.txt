SET (sources
    Exception.cpp
)

SET (headers
    Exception.h
)

SET (full_sources
    ${sources}
    ${headers}
)

ADD_LIBRARY(ibi_error SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi_error ${LIBS})
