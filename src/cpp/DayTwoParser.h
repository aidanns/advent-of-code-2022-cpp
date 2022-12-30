//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H
#define ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H

#include <string>
#include <vector>

#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo::Parser {

    using HandleRoundCallbackFunction = std::function<void(const RockPaperScissors::Round &)>;

    const std::string kDayTwoInputFilePath = "../src/data/input_day_two.txt";

    /**
     * Parse the complete file, using puzzle one logic.
     *
     * @param inputFilePath path to read from
     * @return all Rock, Paper, Scissors game rounds parsed from the file
     */
    std::vector<RockPaperScissors::Round> parseFilePuzzleOne(const std::string &inputFilePath);

    /**
     * Parse the file one round at a time, providing each one to a specified handler, using puzzle one logic.
     *
     * @param inputFilePath path to read from
     * @param handleRoundCallback callback to process each parsed Round
     */
    void parseFilePuzzleOne(const std::string &inputFilePath, const HandleRoundCallbackFunction &&handleRoundCallback);

    /**
     * Parse the complete file, using puzzle two logic.
     *
     * @param inputFilePath path to read from
     * @return all Rock, Paper, Scissors game rounds parsed from the file
     */
    std::vector<RockPaperScissors::Round> parseFilePuzzleTwo(const std::string &inputFilePath);

    /**
     * Parse the file one round at a time, providing each one to a specified handler, using puzzle two logic.
     *
     * @param inputFilePath path to read from
     * @param handleRoundCallback callback to process each parsed Round
     */
    void parseFilePuzzleTwo(const std::string &inputFilePath, const HandleRoundCallbackFunction &&handleRoundCallback);

} // AdventOfCode::DayTwo::Parser

#endif //ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H
