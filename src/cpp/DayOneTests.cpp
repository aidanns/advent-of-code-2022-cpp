#include <gtest/gtest.h>

#include "DayOne.h"
#include "DayOneParser.h"

namespace AdventOfCode::DayOne {
    TEST(DayOne, puzzleOneAnswer) {
        const auto input = Parser::parseFile(Parser::kDayOneInputFilePath);
        EXPECT_EQ(69528, DayOne::puzzleOneSolution(input));
    }

    TEST(DayOne, puzzleTwoAnswer) {
        const auto realInput = Parser::parseFile(Parser::kDayOneInputFilePath);
        EXPECT_EQ(206152, DayOne::puzzleTwoSolution(realInput));
    }
} // AdventOfCode