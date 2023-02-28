cmake_minimum_required(VERSION 3.14)

set(ROOT_PRJ_NAME TBFM)
project(${ROOT_PRJ_NAME} LANGUAGES CXX)

set(ThirdParty_dir ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE headers
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hxx
)

file(GLOB_RECURSE sources
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx
)

add_subdirectory(${ThirdParty_dir}/FTXUI EXCLUDE_FROM_ALL)

add_executable(${ROOT_PRJ_NAME}
  main.cpp
  ${headers}
  ${sources}
)

target_link_libraries(${ROOT_PRJ_NAME} PRIVATE
  ftxui::component
)

target_include_directories(${ROOT_PRJ_NAME} PRIVATE
  $${ThirdParty_dir}/FTXUI/include
)

#install(TARGETS ${ROOT_PRJ_NAME}
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

