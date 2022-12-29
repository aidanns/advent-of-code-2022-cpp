#ifndef DAY_ONE_H
#define DAY_ONE_H

#include "Elf.h"

namespace AdventOfCode::DayOne {

    using Input = std::vector<Elf>;

    void run();

    int puzzleOneSolution(const Input &input);

    /**
     * Returns the answer for day one puzzle one without storing parsed Elf data.
     */
    int puzzleOneSolutionWithoutStorage();

    int puzzleTwoSolution(const Input &input);

    /**
     * Simplest possible implementation of puzzle one that generates the correct answer. Used as a baseline for
     * benchmarking.
     *
     * @param input parsed input for day one
     * @return answer for day one puzzle one
     */
    int puzzleOneSolutionStrawman(const Input &input);

} // AdventOfCode::DayOne

#endif // DAY_ONE_H