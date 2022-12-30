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
    void run();

    /**
     * Calculate the solution for puzzle two.
     *
     * @param input input for day two
     * @return the result for puzzle one
     */
    int puzzleSolution(const Input &input);
}

#endif // DAY_TWO_H
