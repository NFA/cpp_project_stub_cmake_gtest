cmake_minimum_required (VERSION 3.0.0)
project (stub_project)

set (PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set (PROJECT_SRC ${PROJECT_ROOT}/src)

set (PROJECT_INCLUDE ${PROJECT_ROOT}/include)

include_directories(${PROJECT_INCLUDE})

add_definitions ("-std=c++1y -Wall -pedantic-errors -Wconversion")

option(test "Build all tests." OFF)

add_subdirectory(src)

if (test)
  find_package(GTest REQUIRED)
  if (${GTEST_FOUND})
    enable_testing()
    add_subdirectory(test)
  endif()
endif()