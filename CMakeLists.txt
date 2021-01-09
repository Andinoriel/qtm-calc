cmake_minimum_required(VERSION 3.8)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(DEBUG_OPTIONS -m64 -Wall -Wextra -pedantic -Werror)
set(RELEASE_OPTIONS -m64 -O2)

project(qtm-calc)

add_executable(qtm-calc)

target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp)

add_compile_options("$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")