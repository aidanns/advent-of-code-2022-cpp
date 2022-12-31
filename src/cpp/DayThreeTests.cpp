//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayThree.h"
#include "DayThreeParser.h"

namespace AdventOfCode::DayThree {
    TEST(DayThree, puzzleOneResults) {
        EXPECT_EQ(2, puzzleOneSolution({Rucksack::builder()
            .withCompartmentOneContent(Item{ItemType::a})
            .withCompartmentOneContent(Item{ItemType::b})
            .withCompartmentTwoContent(Item{ItemType::b})
            .withCompartmentTwoContent(Item{ItemType::c})
            .build()}));
    }

    TEST(DayThree, puzzleOneSolution) {
        auto input = Parser::parseFilePuzzleOne(Parser::kDayThreeInputFilePath);
        EXPECT_EQ(8039, puzzleOneSolution(input));
    }

    TEST (DayThree, puzzleTwoSolution) {
        auto input = Parser::parseFilePuzzleOne(Parser::kDayThreeInputFilePath);
        EXPECT_EQ(2510, puzzleTwoSolution(input));
    }
}

