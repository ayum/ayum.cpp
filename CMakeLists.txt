cmake_minimum_required(VERSION 3.13)

project(ayum
    VERSION 0.1.0
    DESCRIPTION "Unordered collection of c++ pieces of code"
    LANGUAGES CXX;C
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/tools/cmake)

get_directory_property(hasParent PARENT_DIRECTORY)
if(NOT hasParent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options($<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall\;-Wextra\;-Werror>)
add_compile_options($<$<CXX_COMPILER_ID:GNU>:-fdirectives-only>)
# Should be enabled when CLI11 library will support it
# add_compile_options($<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-fno-rtti>)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(SYSTEM external)

option(BUILD_TESTING "Build tests and include it in library" OFF)
include(CTest)
include(FindPkgConfig)

set(PMM_URL_BASE "file://${CMAKE_CURRENT_LIST_DIR}/tools/pmm")
include(pmm.cmake)

endif()

add_subdirectory(libs/com/github/ayum)

## Settle on default, if not uncomment
# if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#     set(CMAKE_INSTALL_PREFIX "/opt/ayum" CACHE PATH "..." FORCE)
# endif()

set(EXCLUDE_FROM_ALL_IF_HAS_PARENT "")
if(hasParent)
set(EXCLUDE_FROM_ALL_IF_HAS_PARENT EXCLUDE_FROM_ALL)
endif()
install(EXPORT ayum DESTINATION share/ayum ${EXCLUDE_FROM_ALL_IF_HAS_PARENT})
