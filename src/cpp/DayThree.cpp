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
        std::cout << "Day 3 - Puzzle 2" << std::endl
                  << "Sum of item priorities: " << puzzleTwoSolution(puzzleOneInput) << std::endl;
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

    int puzzleTwoSolution(const Input &input) {

        auto inputIsValid = [](const Input &input) -> bool {
            return input.size() % 3 == 0;
        };

        if (!inputIsValid(input)) {
            return -1;
        }

        int sumOfPriorities = 0;
        for (int i = 0; i < input.size(); i += 3) {
            Rucksack one = input.at(i);
            Rucksack two = input.at(i + 1);
            Rucksack three = input.at(i + 2);

            for (const auto &item : one.compartmentOne().items()) {
                auto rucksackTwoContains = two.compartmentOne().contains(item)
                        || two.compartmentTwo().contains(item);
                auto rucksackThreeContains = three.compartmentOne().contains(item)
                        || three.compartmentTwo().contains(item);

                if (rucksackTwoContains && rucksackThreeContains) {
                    sumOfPriorities += item.priority();
                    break;
                }
            }

            for (const auto &item : one.compartmentTwo().items()) {
                auto rucksackTwoContains = two.compartmentOne().contains(item)
                                           || two.compartmentTwo().contains(item);
                auto rucksackThreeContains = three.compartmentOne().contains(item)
                                             || three.compartmentTwo().contains(item);

                if (rucksackTwoContains && rucksackThreeContains) {
                    sumOfPriorities += item.priority();
                    break;
                }
            }
        }

        return sumOfPriorities;
    }
}
