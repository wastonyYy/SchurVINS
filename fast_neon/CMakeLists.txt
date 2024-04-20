project(fast)
cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas")

# set(ENV{ARM_ARCHITECTURE} aarch64)
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64")
  add_definitions(-D__ARM_NEON__)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native")
ELSE()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mmmx -msse -msse -msse2 -msse3 -mssse3 -fomit-frame-pointer")
ENDIF()

find_package(catkin_simple REQUIRED)
catkin_simple()

set(HEADERS
  include/fast/corner_9.h
  include/fast/corner_10.h
  include/fast/fast.h
  include/fast/faster_corner_utilities.h
  )

set(SOURCES
  src/fast_9.cpp
  src/fast_10.cpp
  src/fast_10_score.cpp
  src/nonmax_3x3.cpp
  )

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64")
  LIST(APPEND SOURCES ${PROJECT_SOURCE_DIR}/src/faster_corner_9_neon.cpp)
ELSE()
  LIST(APPEND SOURCES ${PROJECT_SOURCE_DIR}/src/faster_corner_10_sse.cpp)
ENDIF()

cs_add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

################################################################################
cs_install()
cs_export()
