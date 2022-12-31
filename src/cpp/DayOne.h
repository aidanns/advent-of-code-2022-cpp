#ifndef DAY_ONE_H
#define DAY_ONE_H

#include "Elf.h"

namespace AdventOfCode::DayOne {

    using Input = std::vector<Elf>;

    /**
     * Generate solutions for both puzzles and print the output to stdout.
     */
    auto run() -> void;

    /**
     * Returns the output for day one puzzle one.
     */
    auto puzzleOneSolution(const Input &input) -> int;

    /**
     * Returns the answer for day one puzzle one without storing parsed Elf data.
     */
    auto puzzleOneSolutionWithoutStorage() -> int;

    /**
     * Returns the answer for day one puzzle two.
     */
    auto puzzleTwoSolution(const Input &input) -> int;

    /**
     * Simplest possible implementation of puzzle one that generates the correct answer. Used as a baseline for
     * benchmarking.
     *
     * @param input parsed input for day one
     * @return answer for day one puzzle one
     */
    auto puzzleOneSolutionStrawman(const Input &input) -> int;
} // AdventOfCode::DayOne

#endif // DAY_ONE_H