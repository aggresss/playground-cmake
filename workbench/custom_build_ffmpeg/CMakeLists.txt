cmake_minimum_required(VERSION 3.0)
project(ffmpeg_hello VERSION 0.0.1)
INCLUDE(ExternalProject)

EXTERNALPROJECT_ADD(
  ffmpeg
  URL https://ffmpeg.org/releases/ffmpeg-6.1.tar.bz2
  CONFIGURE_COMMAND
  PATH=$ENV{PATH} PKG_CONFIG_PATH=$ENV{PKG_CONFIG_PATH} ./configure
    --prefix=${CMAKE_BINARY_DIR}
    --datadir=${CMAKE_BINARY_DIR}/etc
    --enable-shared
    --enable-static
    --enable-gpl
    --enable-version3
    --enable-nonfree
    --enable-runtime-cpudetect
    --disable-doc
    --disable-debug
    --disable-ffplay
    --disable-indevs
    --disable-outdevs

  BUILD_COMMAND PATH=$ENV{PATH} make
  BUILD_IN_SOURCE 1
)

# PATH 01
find_library(AVUTIL_LIBRARY
    NAMES avutil
    HINTS "${CMAKE_BINARY_DIR}/lib"
)
add_library(avutil SHARED IMPORTED)
set_target_properties(avutil PROPERTIES
  IMPORTED_LOCATION ${AVUTIL_LIBRARY}
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_BINARY_DIR}/include"
)
add_executable(ffmpeg_hello src/ffmpeg_hello.c)
target_link_libraries(ffmpeg_hello avutil)

# PATH 02
# include_directories(${CMAKE_BINARY_DIR}/include)
# find_library(avutil
#     NAMES avutil
#     HINTS "${CMAKE_BINARY_DIR}/lib"
# )
# add_executable(ffmpeg_hello src/ffmpeg_hello.c)
# target_link_libraries(ffmpeg_hello ${avutil})

# PATH 03
# include_directories(${CMAKE_BINARY_DIR}/include)
# link_directories(${CMAKE_BINARY_DIR}/lib)
# add_executable (ffmpeg_hello src/ffmpeg_hello.c)
# target_link_libraries(ffmpeg_hello avutil)
