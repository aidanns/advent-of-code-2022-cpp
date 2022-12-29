#ifndef DAY_ONE_H
#define DAY_ONE_H

#include "Elf.h"

namespace AdventOfCode::DayOne {

    void run();

    int puzzleOneSolution(const std::vector<Elf> &elves);
    int puzzleOneSolutionStrawman(const std::vector<Elf> &elves);
    int puzzleTwoSolution(const std::vector<Elf> &elves);

} // AdventOfCode::DayOne

#endif // DAY_ONE_H