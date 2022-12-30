//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayThree.h"

#include <iostream>

#include "DayThreeParser.h"

namespace AdventOfCode::DayThree {

    void run() {
        Input puzzleOneInput = Parser::parseFilePuzzleOne(Parser::kDayThreeInputFilePath);
        std::cout << "Day 3 - Puzzle 1" << std::endl
                  << "Sum of item priorities: " << puzzleOneSolution(puzzleOneInput) << std::endl;
    }

    int puzzleOneSolution(const Input &input) {
        int sumOfPriorities = 0;
        for (const auto &rucksack : input) {
            for (const auto &item : rucksack.compartmentOne().items()) {
                if (rucksack.compartmentTwo().contains(item)) {
                    sumOfPriorities += item.priority();
                    break;
                }
            }
        }
        return sumOfPriorities;
    }
}
