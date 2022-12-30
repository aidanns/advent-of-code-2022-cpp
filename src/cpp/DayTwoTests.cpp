//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayTwo.h"
#include "DayTwoParser.h"
#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo {
    TEST(DayTwo, puzzleOneResults) {
        EXPECT_EQ(5, puzzleSolution({{RockPaperScissors::Selection::kPaper, RockPaperScissors::kPaper}}));
        EXPECT_EQ(1, puzzleSolution({{RockPaperScissors::Selection::kPaper, RockPaperScissors::kRock}}));
        EXPECT_EQ(9, puzzleSolution({{RockPaperScissors::Selection::kPaper, RockPaperScissors::kScissors}}));
    }

    TEST(DayTwo, puzzleOneSolution) {
        auto input = Parser::parseFilePuzzleOne(Parser::kDayTwoInputFilePath);
        EXPECT_EQ(12740, puzzleSolution(input));
    }

    TEST (DayTwo, puzzleTwoSolution) {
        auto input = Parser::parseFilePuzzleTwo(Parser::kDayTwoInputFilePath);
        EXPECT_EQ(11980, puzzleSolution(input));
    }
}

