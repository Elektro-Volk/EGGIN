cmake_minimum_required(VERSION 2.8)
project(EGGIN)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Three party
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/tparty/irrlicht/include )

# Engine source files
include_directories( src/ )
include( src/core/Core.cmake )
# Engine systems
include( src/systems/Render/Render.cmake )

add_library(EGGIN STATIC ${S_CORE} ${S_RENDER})
