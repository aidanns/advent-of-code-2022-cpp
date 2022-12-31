//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayThreeParser.h"

namespace AdventOfCode::DayThree::Parser {

    constexpr int kDayThreeInputNumberOfRounds = 300;
    constexpr int kRucksackOneCompartmentOneItemOnePriority = 17;
    constexpr int kRucksackOneCompartmentTwoItemOnePriority = 10;

    TEST(DayThreeParser, Parses) {
        auto rucksacks = parseFilePuzzleOne(kDayThreeInputFilePath);

        EXPECT_EQ(kDayThreeInputNumberOfRounds, rucksacks.size());
        EXPECT_EQ(kRucksackOneCompartmentOneItemOnePriority, rucksacks.at(0).compartmentOne().items().at(0).priority());
        EXPECT_EQ(kRucksackOneCompartmentTwoItemOnePriority, rucksacks.at(0).compartmentTwo().items().at(0).priority());
    }

    TEST(DayThreeParser, benchmarkParseComplete) {
        ankerl::nanobench::Bench().run("Day 3 Parse - Batch", [&]() {
            ankerl::nanobench::doNotOptimizeAway(Parser::parseFilePuzzleOne(Parser::kDayThreeInputFilePath));
        });
    }

    TEST(DayThreeParser, benchmarkParseWithCallback) {
        ankerl::nanobench::Bench().run("Day 3 Parse - Callback", [&]() {
            std::vector<Rucksack> rucksacks;
            Parser::parseFile(Parser::kDayThreeInputFilePath, [&](auto &&rucksack) {
                rucksacks.push_back(std::forward<decltype(rucksack)>(rucksack));
            });
            ankerl::nanobench::doNotOptimizeAway(rucksacks);
        });
    }
} // AdventOfCode::DayTwo::Parser