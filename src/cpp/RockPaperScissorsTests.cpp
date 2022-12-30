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

    TEST(RockPaperScissors, resultCalculation) {
        EXPECT_EQ(kPlayerOneWin, resultFromRound({kRock, kScissors}));
        EXPECT_EQ(kPlayerOneWin, resultFromRound({kPaper, kRock}));
        EXPECT_EQ(kPlayerOneWin, resultFromRound({kScissors, kPaper}));
        EXPECT_EQ(kDraw, resultFromRound({kRock, kRock}));
        EXPECT_EQ(kDraw, resultFromRound({kScissors, kScissors}));
        EXPECT_EQ(kDraw, resultFromRound({kPaper, kPaper}));
        EXPECT_EQ(kPlayerTwoWin, resultFromRound({kScissors, kRock}));
        EXPECT_EQ(kPlayerTwoWin, resultFromRound({kRock, kPaper}));
        EXPECT_EQ(kPlayerTwoWin, resultFromRound({kPaper, kScissors}));
    }

    TEST(RockPaperScissors, roundCreationBenchmark) {
        ankerl::nanobench::Bench().run("Day 2 - Rock, Paper, Scissors round creation", [&]() {
            ankerl::nanobench::doNotOptimizeAway(RockPaperScissors::Round(kRock, kPaper));
        });
    }

}