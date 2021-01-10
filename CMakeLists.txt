cmake_minimum_required(VERSION 3.8)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

project(qtm-calc)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(qtm-calc)

target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp)

target_link_libraries(qtm-calc ${ARMADILLO_LIBRARIES})