add_library(ayum-dld INTERFACE ${EXCLUDE_FROM_ALL_IF_HAS_PARENT})

target_sources(ayum-dld INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/dld.cpp>
    $<INSTALL_INTERFACE:include/ayum/dld.cpp>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/dld.hpp>
    $<INSTALL_INTERFACE:include/ayum/dld.hpp>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/dld.test.cpp>
    $<INSTALL_INTERFACE:include/ayum/dld.test.cpp>
)

target_include_directories(ayum-dld INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/ayum>
)
set_target_properties(ayum-dld PROPERTIES
    PUBLIC_HEADER "dld.hpp;dld.cpp;dld.test.cpp"
    EXPORT_NAME dld
)

add_library(ayum::dld ALIAS ayum-dld)

install(TARGETS ayum-dld EXPORT ayum_targets
    PUBLIC_HEADER DESTINATION include/ayum
)

if(BUILD_TESTING)
add_library(ayum-dld-test INTERFACE ${EXCLUDE_FROM_ALL_IF_HAS_PARENT})

target_compile_definitions(ayum-dld-test INTERFACE COM_GITHUB_AYUM_DLD_TEST)

find_package(doctest CONFIG REQUIRED)
target_link_libraries(ayum-dld-test INTERFACE doctest::doctest)

set_target_properties(ayum-dld-test PROPERTIES
    EXPORT_NAME dld-test
)

add_library(ayum::dld-test ALIAS ayum-dld-test)

install(TARGETS ayum-dld-test EXPORT ayum_targets)

add_executable(ayum-dld-test-exe ${EXCLUDE_FROM_ALL_IF_HAS_PARENT} $<TARGET_OBJECTS:ayum-test-main>)
set_target_properties(ayum-dld-test-exe PROPERTIES OUTPUT_NAME ayum-dld-test)
target_link_libraries(ayum-dld-test-exe PRIVATE ayum-dld ayum-dld-test)

find_package(doctest CONFIG REQUIRED)
target_link_libraries(ayum-dld-test-exe PRIVATE doctest::doctest)

install(TARGETS ayum-dld-test-exe ${EXCLUDE_FROM_ALL_IF_HAS_PARENT}
    RUNTIME DESTINATION bin
)
endif()
