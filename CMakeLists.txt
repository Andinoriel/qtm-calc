cmake_minimum_required(VERSION 3.12)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)

project(qtm-calc)

find_package(Boost)
if(Boost_FOUND) 
  include_directories(${Boost_INCLUDE_DIRS})

  add_executable(qtm-calc)
  
  target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp)
  target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-data.cpp)
  target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-json.cpp)
  target_sources(qtm-calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

  target_link_libraries(qtm-calc ${Boost_LIBRARIES})


  add_subdirectory(extern/pybind11)
  pybind11_add_module(libqtmcalc)

  target_sources(libqtmcalc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-core.cpp)
  target_sources(libqtmcalc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/qtm-data.cpp)
  target_sources(libqtmcalc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main_export.cpp)

  target_compile_definitions(libqtmcalc PRIVATE _LIBQTMCALC_ENABLE_PYBIND11_EXPORT)
  target_link_libraries(libqtmcalc PRIVATE ${Boost_LIBRARIES})
endif()
