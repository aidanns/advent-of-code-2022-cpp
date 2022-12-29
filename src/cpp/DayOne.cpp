#include <iostream>
#include <string>
#include <vector>

#include "DayOne.h"
#include "DayOneParser.h"
#include "Elf.h"

namespace AdventOfCode::DayOne {

    int puzzleOneSolution(const std::vector<Elf> & elves) {
        int largestCalorieCountForElf = 0;
        for (const auto & elf : elves) {
            if (elf.totalCarriedCalories() > largestCalorieCountForElf) {
                largestCalorieCountForElf = elf.totalCarriedCalories();
            }
        }
        return largestCalorieCountForElf;
    }

    int puzzleOneSolutionStrawman(const std::vector<Elf> &elves) {
        return 69528;
    }

    int puzzleTwoSolution(const std::vector<Elf> & elves) {

        int largestCalorieCount = 0;
        int secondLargestCalorieCount = 0;
        int thirdLargestCalorieCount = 0;

        for (const auto & elf : elves) {
            if (elf.totalCarriedCalories() > largestCalorieCount) {
                thirdLargestCalorieCount = secondLargestCalorieCount;
                secondLargestCalorieCount = largestCalorieCount;
                largestCalorieCount = elf.totalCarriedCalories();
            } else if (elf.totalCarriedCalories() > secondLargestCalorieCount) {
                thirdLargestCalorieCount = secondLargestCalorieCount;
                secondLargestCalorieCount = elf.totalCarriedCalories();
            } else if (elf.totalCarriedCalories() > thirdLargestCalorieCount) {
                thirdLargestCalorieCount = elf.totalCarriedCalories();
            }
        }

        return largestCalorieCount + secondLargestCalorieCount + thirdLargestCalorieCount;
    }

    void run() {
        std::vector<Elf> elves = Parser::parseFile(Parser::kDayOneInputFilePath);

        std::cout << "Day 1 - Puzzle 1" << std::endl
                  << "Maximum carried by one elf is: " << puzzleOneSolution(elves) << std::endl;
        std::cout << "Day 1 - Puzzle 2" << std::endl
                  << "Total carried by largest three elves: " << puzzleTwoSolution(elves) << std::endl;
    }
} // AdventOfCode::DayOne