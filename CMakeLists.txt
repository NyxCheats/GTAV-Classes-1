cmake_minimum_required(VERSION 3.11)

project(GTAV-Classes)

include(CheckIncludeFileCXX)

file(GLOB_RECURSE HEADERS "**.hpp")
file(GLOB_RECURSE SRC_MAIN "classes.cpp")
source_group(FILES ${SRC_MAIN})
add_library(GTAV-Classes MODULE "${SRC_MAIN}")

set_property(TARGET GTAV-Classes PROPERTY CXX_STANDARD 23)

add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

message(STATUS "")
 
target_include_directories(GTAV-Classes PRIVATE 
    "${SRC_DIR}"
)

