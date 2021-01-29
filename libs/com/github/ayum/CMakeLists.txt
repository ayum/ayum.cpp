if(BUILD_TESTING AND NOT hasParent)
_pmm(VCPKG REVISION 2020.11-1 REQUIRES doctest)
endif()

add_subdirectory(dld)

if(BUILD_TESTING)

add_executable(ayum-test ${EXCLUDE_FROM_ALL_IF_HAS_PARENT} main.cc)

target_link_libraries(ayum-test PRIVATE "-Wl,--whole-archive" ayum::dld "-Wl,--no-whole-archive")

find_package(doctest CONFIG REQUIRED)
target_link_libraries(ayum-test PRIVATE doctest::doctest)

endif()
