//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "DayOneParser.h"
#include "Elf.h"

namespace AdventOfCode::DayOne::Parser {

    constexpr int kDayOneInputNumberOfElves = 254;
    constexpr int kDayOneInputFirstElfFirstFoodCalories = 15560;
    constexpr int kDayOneInputFirstElfTotalCalories = 50030;

    TEST(DayOneParser, Parses) {
        auto elves = parseFile(kDayOneInputFilePath);

        EXPECT_EQ(kDayOneInputNumberOfElves, elves.size());
        EXPECT_EQ(kDayOneInputFirstElfFirstFoodCalories, elves.at(0).carriedFood().at(0).calories());
        EXPECT_EQ(kDayOneInputFirstElfTotalCalories, elves.at(0).totalCarriedCalories());
    }

    TEST(DayOneParser, benchmarkParseComplete) {
        ankerl::nanobench::Bench().run("Day 1 Parse - Batch", [&]() {
            ankerl::nanobench::doNotOptimizeAway(Parser::parseFile(Parser::kDayOneInputFilePath));
        });
    }

    TEST(DayOneParser, benchmarkParseWithCallback) {
        ankerl::nanobench::Bench().run("Day 1 Parse - Callback", [&]() {
            std::vector<Elf> elves;
            Parser::parseFile(Parser::kDayOneInputFilePath,[&](const Elf &elf) {
                   elves.push_back(elf);
               });
            ankerl::nanobench::doNotOptimizeAway(elves);
        });
    }
} // AdventOfCode