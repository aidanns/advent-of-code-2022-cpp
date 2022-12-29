#include <iostream>
#include <string>
#include <vector>

#include "DayOne.h"
#include "DayOneParser.h"
#include "Elf.h"

namespace AdventOfCode::DayOne {

    int puzzleOneSolution(const Input &input) {
        int largestCalorieCountForElf = 0;
        for (const auto & elf : input) {
            if (elf.totalCarriedCalories() > largestCalorieCountForElf) {
                largestCalorieCountForElf = elf.totalCarriedCalories();
            }
        }
        return largestCalorieCountForElf;
    }

    int puzzleOneSolutionWithoutStorage() {
        int largestCalorieCountElf = 0;
        Parser::parseFile(Parser::kDayOneInputFilePath, [&](const Elf &elf) {
            if (elf.totalCarriedCalories() > largestCalorieCountElf) {
                largestCalorieCountElf = elf.totalCarriedCalories();
            }
        });
        return largestCalorieCountElf;
    }

    int puzzleOneSolutionStrawman(const Input &input) {
        return 69528;
    }

    int puzzleTwoSolution(const Input &input) {

        int largestCalorieCount = 0;
        int secondLargestCalorieCount = 0;
        int thirdLargestCalorieCount = 0;

        for (const auto &elf : input) {
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
        Input input = Parser::parseFile(Parser::kDayOneInputFilePath);

        std::cout << "Day 1 - Puzzle 1" << std::endl
                  << "Maximum carried by one elf is: " << puzzleOneSolution(input) << std::endl;
        std::cout << "Day 1 - Puzzle 2" << std::endl
                  << "Total carried by largest three input: " << puzzleTwoSolution(input) << std::endl;
    }
} // AdventOfCode::DayOne