cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
project(find_x VERSION 0.0.1)
set(CMAKE_VERBOSE_MAKEFILE ON)
message(STATUS "hello")

find_package(FFmpeg REQUIRED COMPONENTS avcodec avutil avformat)

message(STATUS ${FFMPEG_LIBRARIES})

find_package(PkgConfig)
