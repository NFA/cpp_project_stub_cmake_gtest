find_package(Threads REQUIRED)
include(ExternalProject)

set(GTEST_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/gtest")
ExternalProject_Add(GTestExternal
 SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk
 SVN_REVISION -r HEAD
 TIMEOUT 10
 PREFIX "${GTEST_PREFIX}"
 INSTALL_COMMAND "")

set(LIBPREFIX "${CMAKE_STATIC_LIBRARY_PREFIX}")
set(LIBSUFFIX "${CMAKE_STATIC_LIBRARY_SUFFIX}")
set(GTEST_LOCATION "${GTEST_PREFIX}/src/GTestExternal-build")
set(GTEST_LIBRARY "${GTEST_LOCATION}/${LIBPREFIX}gtest${LIBSUFFIX}")
set(GTEST_MAINLIB "${GTEST_LOCATION}/${LIBPREFIX}gtest_main${LIBSUFFIX}")

add_library(GTest IMPORTED STATIC GLOBAL)
set_target_properties(GTest PROPERTIES
 "IMPORTED_LOCATION" "${GTEST_LIBRARY}"
 "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")

add_library(GTestMain IMPORTED STATIC GLOBAL)
set_target_properties(GTestMain PROPERTIES
 "IMPORTED_LOCATION" "${GTEST_MAINLIB}"
 "IMPORTED_LINK_INTERFACE_LIBRARIES"
 "${GTEST_LIBRARY};${CMAKE_THREAD_LIBS_INIT}")

add_dependencies(GTest GTestExternal)

ExternalProject_Get_Property(GTestExternal source_dir)
set(GTEST_INCLUDE ${source_dir}/include)
include_directories(${GTEST_INCLUDE})

file(GLOB TEST_SRC_FILES *.cpp)

add_executable(unit_tests
    ${TEST_SRC_FILES}
)

target_link_libraries(unit_tests GTestMain math)

add_test(NAME tests COMMAND unit_tests)

