if(NOT VCPKG_CMAKE_SYSTEM_NAME OR VCPKG_CMAKE_SYSTEM_NAME STREQUAL "windows" OR VCPKG_CMAKE_SYSTEM_NAME STREQUAL "WindowsStore")
    message(FATAL_ERROR "Currently ayum only supports Linux platforms")
endif()

vcpkg_check_linkage(ONLY_STATIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO ayum/ayum.github.com
    REF 2b9e6c5afba24d0a06e1a433e46f4717df8f40db
    SHA512 7606bd8340fe78d8d6260b4b2dd4b4ce85d6397e63daf7576f78fb6465a2d1776cd7c8fb96c8569cb674aaad3979c29ad83b2986a47c398027b363248f68f84f
    HEAD_REF main
)

vcpkg_configure_cmake(
    SOURCE_PATH ${SOURCE_PATH}
    PREFER_NINJA
)

vcpkg_install_cmake()

if (NOT VCPKG_CMAKE_SYSTEM_NAME OR VCPKG_CMAKE_SYSTEM_NAME STREQUAL "windows" OR VCPKG_CMAKE_SYSTEM_NAME STREQUAL "WindowsStore") #Windows
    vcpkg_fixup_cmake_targets(CONFIG_PATH CMake)
else() #Linux/Unix/Darwin
    vcpkg_fixup_cmake_targets(CONFIG_PATH lib/cmake/ayum)
endif()

file(REMOVE_RECURSE
    "${CURRENT_PACKAGES_DIR}/debug"
    "${CURRENT_PACKAGES_DIR}/bin"
    "${CURRENT_PACKAGES_DIR}/lib"
)

# Handle copyright
file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/ayum" RENAME copyright)
