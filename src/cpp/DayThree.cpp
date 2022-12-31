//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayThree.h"

#include <algorithm>
#include <iostream>

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
            auto compartmentTwoContainsItemPredicate = [&](const auto &item) -> bool {
                return rucksack.compartmentTwo().contains(item);
            };
            auto compartmentOneItems = rucksack.compartmentOne().items();
            auto iter = std::find_if(
                    compartmentOneItems.begin(),
                    compartmentOneItems.end(),
                    compartmentTwoContainsItemPredicate);
            sumOfPriorities += iter->priority();
        }
        return sumOfPriorities;
    }

    auto puzzleTwoSolution(const Input &input) -> PuzzleTwoSolution {

        bool inputIsValid = (input.size() % 3 == 0);
        if (!inputIsValid) {
            return -1;
        }

        int sumOfPriorities = 0;
        for (int i = 0; i < input.size(); i += 3) {
            const Rucksack& one = input.at(i);
            const Rucksack& two = input.at(i + 1);
            const Rucksack& three = input.at(i + 2);

            auto rucksackTwoAndThreeContainsItemPredicate = [&](const auto &item) -> bool {
                auto rucksackTwoContains = two.compartmentOne().contains(item)
                        || two.compartmentTwo().contains(item);
                auto rucksackThreeContains = three.compartmentOne().contains(item)
                        || three.compartmentTwo().contains(item);
                return rucksackTwoContains && rucksackThreeContains;
            };

            std::set<Item> rucksackOneItems = one.allUniqueItems();
            // TODO(aidanns): Update this to use ranges when new Clang installed.
            auto commonItem = std::find_if(
                    rucksackOneItems.begin(),
                    rucksackOneItems.end(),
                    rucksackTwoAndThreeContainsItemPredicate);
            sumOfPriorities += commonItem->priority();
        }

        return sumOfPriorities;
    }
}
