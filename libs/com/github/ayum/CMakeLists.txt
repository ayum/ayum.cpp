if(BUILD_TESTING AND NOT hasParent)
_pmm(VCPKG REVISION 2020.11-1 REQUIRES doctest)
endif()

if(BUILD_TESTING)

add_library(ayum-test-main OBJECT ${EXCLUDE_FROM_ALL_IF_HAS_PARENT} main.cc)

find_package(doctest CONFIG REQUIRED)
target_link_libraries(ayum-test-main PRIVATE doctest::doctest)

endif()

add_subdirectory(dld)
