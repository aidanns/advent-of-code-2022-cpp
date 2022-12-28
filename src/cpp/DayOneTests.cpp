#include <gtest/gtest.h>

#include "DayOne.h"
#include "DayOneParser.h"

namespace AdventOfCode {
    TEST(DayOne, puzzleOneAnswer) {
        const auto input = DayOneParser::parseFile(DayOneParser::kDayOneInputFilePath);
        EXPECT_EQ(69528, DayOne::puzzleOneSolution(input));
    }

    TEST(DayOne, puzzleTwoAnswer) {
        const auto realInput = DayOneParser::parseFile(DayOneParser::kDayOneInputFilePath);
        EXPECT_EQ(206152, DayOne::puzzleTwoSolution(realInput));
    }
} // AdventOfCode