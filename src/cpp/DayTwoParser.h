//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H
#define ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H

#include <string>
#include <vector>

#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo::Parser {

    const std::string kDayTwoInputFilePath = "../src/data/input_day_two.txt";

    /**
     * Parse the complete file.
     *
     * @param round path to read from
     * @return all Rock, Paper, Scissors game rounds parsed from the file
     */
    std::vector<RockPaperScissors::Round> parseFile(const std::string &round);

    /**
     * Parse the file one round at a time, providing each one to a specified handler.
     *
     * @param inputFilePath path to read from
     * @param handleRoundCallback callback to process each parsed Round
     */
    void parseFile(const std::string &inputFilePath, std::function<void(RockPaperScissors::Round)> &&handleRoundCallback);

} // AdventOfCode::DayTwo::Parser

#endif //ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H
