project(HELLO)
set(CMAKE_VERBOSE_MAKEFILE ON)
message(STATUS "hello")

add_executable(foo main.cpp)

set(GEN_SRC
    ${CMAKE_BINARY_DIR}/main.cpp
)

add_custom_command(
    OUTPUT ${GEN_SRC}
    COMMAND ${CMAKE_COMMAND} -E copy main.in.cpp ${CMAKE_BINARY_DIR}/main.cpp
    DEPENDS main.in.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
