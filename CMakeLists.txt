
cmake_minimum_required(VERSION 3.15)

project(NPLot
        VERSION 0.0.1
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Release)  # Choose Release, Debug, etc.
endif()

add_compile_options(
        "-Wno-array-bounds"
        "-Wno-error=stringop-overflow"
)

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(sandbox)

