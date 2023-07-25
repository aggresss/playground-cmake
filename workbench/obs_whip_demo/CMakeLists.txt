cmake_minimum_required(VERSION 3.0)
project(curl_hello VERSION 0.0.1)
set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

find_package(CURL REQUIRED)
add_executable (curl_hello curl_hello.cpp)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(curl_hello ${CURL_LIBRARIES})
