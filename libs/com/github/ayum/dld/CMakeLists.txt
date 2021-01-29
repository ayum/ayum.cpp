add_library(com.github.ayum.dld STATIC ${EXCLUDE_FROM_ALL_IF_HAS_PARENT}
    dld.cpp dld.hpp
)
if(BUILD_TESTING)
target_sources(com.github.ayum.dld PRIVATE dld.test.cpp)
endif()

target_include_directories(com.github.ayum.dld INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/ayum>
)
set_target_properties(com.github.ayum.dld PROPERTIES PUBLIC_HEADER
    dld.hpp
)

if(BUILD_TESTING)
find_package(doctest CONFIG REQUIRED)
target_link_libraries(com.github.ayum.dld PRIVATE doctest::doctest)
endif()

add_library(ayum::dld ALIAS com.github.ayum.dld)

install(TARGETS com.github.ayum.dld EXPORT ayum
    ARCHIVE
    PUBLIC_HEADER
)
