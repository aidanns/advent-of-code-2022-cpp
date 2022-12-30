//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo::RockPaperScissors {

    TEST(RockPaperScissors, roundCreation) {
        const auto round = RockPaperScissors::Round(Selection::kPaper, Selection::kRock);

        EXPECT_EQ(kPaper, round.playerOneSelection());
        EXPECT_EQ(kRock, round.playerTwoSelection());
    }

    TEST(RockPaperScissors, selectionPointValues) {
        EXPECT_EQ(1, RockPaperScissors::pointValueForSelection(Selection::kRock));
        EXPECT_EQ(2, RockPaperScissors::pointValueForSelection(Selection::kPaper));
        EXPECT_EQ(3, RockPaperScissors::pointValueForSelection(Selection::kScissors));
    }

    TEST(RockPaperScissors, roundCreationBenchmark) {
        ankerl::nanobench::Bench().run("Day Two - Rock, Paper, Scissors round creation", [&]() {
            ankerl::nanobench::doNotOptimizeAway(RockPaperScissors::Round(kRock, kPaper));
        });
    }

}