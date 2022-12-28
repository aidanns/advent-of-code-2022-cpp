//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#include <gtest/gtest.h>

#include "DayOneParser.h"

namespace AdventOfCode {

    constexpr int kDayOneInputNumberOfElves = 254;
    constexpr int kDayOneInputFirstElfFirstFoodCalories = 15560;
    constexpr int kDayOneInputFirstElfTotalCalories = 50030;

    TEST(DayOneParser, Parses) {
        auto elves = DayOneParser::parseFile(kDayOneInputFilePath);

        EXPECT_EQ(kDayOneInputNumberOfElves, elves.size());
        EXPECT_EQ(kDayOneInputFirstElfFirstFoodCalories, elves.at(0).carriedFood().at(0).calories());
        EXPECT_EQ(kDayOneInputFirstElfTotalCalories, elves.at(0).totalCarriedCalories());
    }
} // AdventOfCode