//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#ifndef DAY_ONE_PARSER_H
#define DAY_ONE_PARSER_H

#include <vector>
#include <fstream>

#include "Elf.h"

namespace AdventOfCode::DayOne::Parser {

    const std::string kDayOneInputFilePath = "../src/data/day_one_puzzle_one.txt";

    std::vector<Elf> parseFile(const std::string &inputFilePath);

} // AdventOfCode::DayOne::Parser

#endif // DAY_ONE_PARSER_H
