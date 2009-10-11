SET (sources
    CommandLineParser.cpp
)

SET (headers
    CommandLineParser.h
)

SET (full_sources
    ${sources}
    ${headers}
)

ADD_LIBRARY(ibi_cmdline SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi_cmdline ${LIBS})