
# plugins
FILE (GLOB cpp_sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

FOREACH (cpp_source ${cpp_sources})
    get_filename_component (target ${cpp_source} NAME_WE)
    add_library (${target} SHARED ${cpp_source})
    target_link_libraries (${target} ${LIBS})
ENDFOREACH (cpp_source)