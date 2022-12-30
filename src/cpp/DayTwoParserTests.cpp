//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayTwoParser.h"

namespace AdventOfCode::DayTwo::Parser {

    constexpr int kDayOneInputNumberOfRounds = 2500;
    constexpr RockPaperScissors::Selection kRoundOnePlayerOneSelection = RockPaperScissors::Selection::kPaper;
    constexpr RockPaperScissors::Selection kRoundOnePlayerTwoSelection = RockPaperScissors::Selection::kPaper;

    TEST(DayTwoParser, Parses) {
        auto rounds = parseFile(kDayTwoInputFilePath);

        EXPECT_EQ(kDayOneInputNumberOfRounds, rounds.size());
        EXPECT_EQ(kRoundOnePlayerOneSelection, rounds.at(0).playerOneSelection());
        EXPECT_EQ(kRoundOnePlayerTwoSelection, rounds.at(0).playerTwoSelection());
    }

    TEST(DayTwoParser, benchmarkParseComplete) {
        ankerl::nanobench::Bench().run("Day 2 Parse - Batch", [&]() {
            ankerl::nanobench::doNotOptimizeAway(Parser::parseFile(Parser::kDayTwoInputFilePath));
        });
    }

    TEST(DayTwoParser, benchmarkParseWithCallback) {
        ankerl::nanobench::Bench().run("Day 2 Parse - Callback", [&]() {
            std::vector<RockPaperScissors::Round> rounds;
            Parser::parseFile(Parser::kDayTwoInputFilePath,[&](const RockPaperScissors::Round &elf) {
                rounds.push_back(elf);
            });
            ankerl::nanobench::doNotOptimizeAway(rounds);
        });
    }
} // AdventOfCode::DayTwo::Parser