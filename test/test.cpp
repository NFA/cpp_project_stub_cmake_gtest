#include <gtest/gtest.h>
#include "math.h"

TEST(AddTest, AssertionTrue) {
    ASSERT_EQ(add(5,5), 10);
}
