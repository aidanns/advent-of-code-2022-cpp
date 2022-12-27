//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#include <gtest/gtest.h>

#include "DayOneParser.h"

namespace AdventOfCode {

    constexpr int kDayOnePuzzleOneInputNumberOfElves = 254;
    const std::string kDayOnePuzzleOneInputFilePath = "../src/data/day_one_puzzle_one.txt";

    TEST(DayOneParser, Parses) {
        auto elves = DayOneParser::parseFile(kDayOnePuzzleOneInputFilePath);

        EXPECT_EQ(kDayOnePuzzleOneInputNumberOfElves, elves.size());
    }

} // AdventOfCode