cmake_minimum_required(VERSION 2.8)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EGGIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
include( ${EGGIN_ROOT}/EGGIN.cmake )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/tparty/irrlicht/include )

# Engine source files
#set(S_CORE main.cpp)

add_executable(HelloWorld main.cpp)
eggin_include_libs( HelloWorld )
