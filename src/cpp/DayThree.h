//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef DAY_THREE_H
#define DAY_THREE_H

#include <vector>

#include "Item.h"
#include "Rucksack.h"

namespace AdventOfCode::DayThree {

    using Input = std::vector<Rucksack>;
    using PuzzleOneSolution = int;
    using PuzzleTwoSolution = int;

    /**
     * Run the calculations for day three and print output to stdout.
     */
    void run();

    /**
     * Calculate the solution for puzzle one.
     *
     * @param input input for day three
     * @return the result for puzzle one
     */
    int puzzleOneSolution(const Input &input);

    /**
     * Calculate the solution for puzzle two.
     *
     * @param input input for day three
     * @return the result for puzzle two
     */
    int puzzleTwoSolution(const Input &input);
}

#endif // DAY_THREE_H
