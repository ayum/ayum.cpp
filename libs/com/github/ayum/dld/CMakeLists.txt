add_library(ayum-dld STATIC ${EXCLUDE_FROM_ALL_IF_HAS_PARENT}
    dld.cpp dld.hpp
)
if(BUILD_TESTING)
target_sources(ayum-dld PRIVATE dld.test.cpp)
endif()

target_include_directories(ayum-dld INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/ayum>
)
set_target_properties(ayum-dld PROPERTIES
    PUBLIC_HEADER dld.hpp
    EXPORT_NAME dld
)

if(BUILD_TESTING)
find_package(doctest CONFIG REQUIRED)
target_link_libraries(ayum-dld PRIVATE doctest::doctest)
endif()

add_library(ayum::dld ALIAS ayum-dld)

install(TARGETS ayum-dld EXPORT ayum
    ARCHIVE
    PUBLIC_HEADER DESTINATION include/ayum
)
