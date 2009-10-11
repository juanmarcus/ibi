SET (sources
    ImageWidget.cpp
)

SET (headers
    ImageWidget.h
)

SET (moc_headers
    ImageWidget.h
)

#generate moc files
QT4_WRAP_CPP(moc_sources ${moc_headers})

SET (full_sources
    ${sources}
    ${headers}
    ${moc_sources}
)

ADD_LIBRARY(ibi_qt SHARED ${full_sources})
TARGET_LINK_LIBRARIES (ibi_qt ${LIBS})