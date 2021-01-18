cmake_minimum_required(VERSION 3.12)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

project(libqtmcalc)

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  
  add_library(libqtmcalc SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp
  )
    
  target_link_libraries(libqtmcalc ${Boost_LIBRARIES})
endif()
