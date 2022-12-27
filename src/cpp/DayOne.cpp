#include <iostream>
#include <string>
#include <vector>

#include "DayOne.h"
#include "DayOneParser.h"
#include "Elf.h"

namespace AdventOfCode {

    int maximumCaloriesForElves(const std::vector<Elf> & elves) {
        int maximumCalories = 0;
        for (const auto & elf : elves) {
            if (elf.totalCarriedCalories() > maximumCalories) {
                maximumCalories = elf.totalCarriedCalories();
            }
        }
        return maximumCalories;
    }

    int DayOne::returnTen() {
        return 10;
    }

    void DayOne::runPuzzleOne() {
        const std::string kDayOnePuzzleOneInputFilePath = "../src/data/day_one_puzzle_one.txt";
        std::vector<Elf> elves = DayOneParser::parseFile(kDayOnePuzzleOneInputFilePath);

        std::cout << "Day 1 - Puzzle 1" << std::endl
                << "Maximum carried by one elf is: " << maximumCaloriesForElves(elves) << std::endl;
    }
} // AdventOfCode