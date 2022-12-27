#include <iostream>
#include <string>
#include <vector>

#include "DayOne.h"
#include "DayOneParser.h"
#include "Elf.h"

namespace AdventOfCode {

    bool compareElvesByCaloriesCarried(const Elf& left, const Elf& right) {
        return (left.totalCarriedCalories() > right.totalCarriedCalories());
    }

    int DayOne::returnTen() {
        return 10;
    }

    void DayOne::runPuzzleOne() {
        const std::string kDayOnePuzzleOneInputFilePath = "../src/data/day_one_puzzle_one.txt";
        std::vector<Elf> elves = DayOneParser::parseFile(kDayOnePuzzleOneInputFilePath);

        std::sort(elves.begin(), elves.end(), compareElvesByCaloriesCarried);
        int largestSingleElfCalorieCount = elves.at(0).totalCarriedCalories();
        int largestThreeElvesCalorieCount = elves.at(0).totalCarriedCalories()
                                            + elves.at(1).totalCarriedCalories()
                                            + elves.at(2).totalCarriedCalories();

        std::cout << "Day 1 - Puzzle 1" << std::endl
                  << "Maximum carried by one elf is: " << largestSingleElfCalorieCount << std::endl;
        std::cout << "Day 1 - Puzzle 2" << std::endl
                  << "Total carried by largest three elves: " << largestThreeElvesCalorieCount << std::endl;
    }
} // AdventOfCode