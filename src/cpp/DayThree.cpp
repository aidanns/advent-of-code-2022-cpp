//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayThree.h"

#include <iostream>
#include <set>

#include "DayThreeParser.h"

namespace AdventOfCode::DayThree {

    auto run() -> void {
        Input puzzleOneInput = Parser::parseFilePuzzleOne(Parser::kDayThreeInputFilePath);
        std::cout << "Day 3 - Puzzle 1" << std::endl
                  << "Sum of item priorities: " << puzzleOneSolution(puzzleOneInput) << std::endl;
        std::cout << "Day 3 - Puzzle 2" << std::endl
                  << "Sum of item priorities: " << puzzleTwoSolution(puzzleOneInput) << std::endl;
    }

    auto puzzleOneSolution(const Input &input) -> PuzzleOneSolution {
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

    auto puzzleTwoSolution(const Input &input) -> PuzzleTwoSolution {

        auto inputIsValid = [](const auto &input) -> bool {
            return input.size() % 3 == 0;
        };

        if (!inputIsValid(input)) {
            return -1;
        }

        int sumOfPriorities = 0;
        for (int i = 0; i < input.size(); i += 3) {
            const Rucksack& one = input.at(i);
            const Rucksack& two = input.at(i + 1);
            const Rucksack& three = input.at(i + 2);

            auto rucksackTwoAndThreeContain = [&](const auto &item) -> bool {
                auto rucksackTwoContains = two.compartmentOne().contains(item)
                                           || two.compartmentTwo().contains(item);
                auto rucksackThreeContains = three.compartmentOne().contains(item)
                                             || three.compartmentTwo().contains(item);
                return rucksackTwoContains && rucksackThreeContains;
            };

            for (const auto &item : one.allUniqueItems()) {
                if (rucksackTwoAndThreeContain(item)) {
                    sumOfPriorities += item.priority();
                    break;
                }
            }
        }

        return sumOfPriorities;
    }
}
