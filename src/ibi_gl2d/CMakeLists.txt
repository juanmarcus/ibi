SET (sources
    GLMode2D.cpp
    Sprite.cpp
)

SET (headers
    GLMode2D.h
    Sprite.h
)

SET (full_sources
    ${sources}
    ${headers}
)

ADD_LIBRARY(ibi_gl2d SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi_gl2d ${LIBS})
