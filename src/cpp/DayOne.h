#ifndef DAY_ONE_H
#define DAY_ONE_H

#include "Elf.h"

namespace AdventOfCode {

    class DayOne {
    public:
        static void runDayOne();
        static int puzzleOneSolution(const std::vector<Elf> &elves);
        static int puzzleTwoSolution(const std::vector<Elf> &elves);
    };

} // AdventOfCode

#endif // DAY_ONE_H