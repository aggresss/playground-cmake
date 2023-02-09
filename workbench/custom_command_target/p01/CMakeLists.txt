cmake_minimum_required(VERSION 3.0)
project(HELLO)
set(CMAKE_VERBOSE_MAKEFILE ON)
message(STATUS "hello")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(foo main.cpp)
set_target_properties(foo PROPERTIES FOLDER "alpha")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT foo)

set(GEN_SRC
    ${CMAKE_BINARY_DIR}/main.cpp
)

add_custom_command(
    OUTPUT ${GEN_SRC}
    COMMAND ${CMAKE_COMMAND} -E copy main.in.cpp ${CMAKE_BINARY_DIR}/main.cpp
    DEPENDS main.in.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_command(
    TARGET foo
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "custom_command before build of foo"
)

add_custom_target(
    admin
    COMMAND ${CMAKE_COMMAND} -E echo "admin"
)

set_target_properties(admin PROPERTIES FOLDER "alpha")
