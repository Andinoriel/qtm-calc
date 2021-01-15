cmake_minimum_required(VERSION 3.12)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

project(qtm-calc)

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  
  add_executable(qtm-calc)
  
  target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp)
  target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-data.cpp)
  
  target_link_libraries(qtm-calc ${Boost_LIBRARIES})
endif()
