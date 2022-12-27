#include <gtest/gtest.h>

#include "DayOne.h"

namespace AdventOfCode {
    TEST(DayOne, ReturnIntegerTest) {
        DayOne dayOne{};
        EXPECT_EQ(10, dayOne.returnTen());
    }
} // AdventOfCode