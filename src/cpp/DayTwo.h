//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef DAY_TWO_H
#define DAY_TWO_H

#include <vector>

#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo {

    /**
     * Input data for day two.
     */
    using Input = std::vector<RockPaperScissors::Round>;

    /**
     * Run the calculations for day two and print output to stdout.
     */
    auto run() -> void;

    /**
     * Calculate the solution for puzzle two.
     *
     * @param input input for day two
     * @return the result for puzzle one
     */
    auto puzzleSolution(const Input &input) -> int;
}

#endif // DAY_TWO_H
