SET (sources
    Texture.cpp
    TextureLoader.cpp
)

SET (headers
    Texture.h
    TextureLoader.h
)

SET (full_sources
    ${sources}
    ${headers}
)

ADD_LIBRARY(ibi_gl SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi_gl ${LIBS})
