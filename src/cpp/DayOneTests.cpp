#include <gtest/gtest.h>
#include <nanobench.h>

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

    TEST(DayOne, puzzleOneBenchmark) {
        const auto input = Parser::parseFile(Parser::kDayOneInputFilePath);

        ankerl::nanobench::Bench().run("Day 1 Puzzle 1", [&]() {
            ankerl::nanobench::doNotOptimizeAway(DayOne::puzzleOneSolution(input));
        });
    }

    TEST(DayOne, puzzleOneBenchmarkStrawman) {
        const auto input = Parser::parseFile(Parser::kDayOneInputFilePath);

        ankerl::nanobench::Bench().run("Day 1 Puzzle 1 Strawman", [&]() {
            ankerl::nanobench::doNotOptimizeAway(DayOne::puzzleOneSolutionStrawman(input));
        });
    }

    TEST(DayOne, puzzleTwoBenchmark) {
        const auto input = Parser::parseFile(Parser::kDayOneInputFilePath);

        ankerl::nanobench::Bench().run("Day 1 Puzzle 2", [&]() {
            ankerl::nanobench::doNotOptimizeAway(DayOne::puzzleTwoSolution(input));
        });
    }
} // AdventOfCode