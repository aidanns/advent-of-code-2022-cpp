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

    auto puzzleOneInnerLoop(const Rucksack &r) -> int {
        auto compartmentTwoContainsItemPredicate = [&](const auto &item) -> bool {
            return r.compartmentTwo().contains(item);
        };
        auto compartmentOneItems = r.compartmentOne().items();
        auto iter = std::find_if(
                compartmentOneItems.begin(),
                compartmentOneItems.end(),
                compartmentTwoContainsItemPredicate);
        return iter != compartmentOneItems.end() ? iter->priority() : 0;
    }

    auto puzzleOneSolutionNoStorage() -> PuzzleOneSolution {
        int sumOfPriorities = 0;
        Parser::parseFile(Parser::kDayThreeInputFilePath, [&](auto &&rucksack) {
            sumOfPriorities += puzzleOneInnerLoop(std::forward<decltype(rucksack)>(rucksack));
        });
        return sumOfPriorities;
    }

    auto puzzleOneSolution(const Input &input) -> PuzzleOneSolution {
        int sumOfPriorities = 0;
        for (const auto &rucksack : input) {
            sumOfPriorities += puzzleOneInnerLoop(rucksack);
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

            // TODO(aidanns): Replace this with a merged std::range after upgrading Clang to support.
            auto maybeCommonItem = std::find_if(
                    one.compartmentOne().items().begin(),
                    one.compartmentOne().items().end(),
                    rucksackTwoAndThreeContainsItemPredicate);
            if (maybeCommonItem != one.compartmentOne().items().end()) {
                sumOfPriorities += maybeCommonItem->priority();
            } else {
                auto commonItem = std::find_if(
                        one.compartmentTwo().items().begin(),
                        one.compartmentTwo().items().end(),
                        rucksackTwoAndThreeContainsItemPredicate);
                sumOfPriorities += commonItem->priority();
            }
        }

        return sumOfPriorities;
    }
}
