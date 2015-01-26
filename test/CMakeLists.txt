include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB TEST_SRC_FILES *.cpp)

add_executable(UnitTests
    ${TEST_SRC_FILES}
)

target_link_libraries(UnitTests ${GTEST_BOTH_LIBRARIES} math)

add_test(NAME UnitTests COMMAND UnitTests)
GTEST_ADD_TESTS(UnitTests "" ${TEST_SRC_FILES})
