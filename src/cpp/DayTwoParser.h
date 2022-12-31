//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H
#define ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H

#include <filesystem>
#include <string>
#include <vector>

#include "RockPaperScissors.h"
#include "DayTwo.h"

namespace AdventOfCode::DayTwo::Parser {

    using HandleRoundCallbackFunction = std::function<void(const RockPaperScissors::Round &)>;

    const auto kDayTwoInputFilePath = "../src/data/input_day_two.txt";

    /**
     * Parse the complete file, using puzzle one logic.
     *
     * @param inputFilePath path to read from
     * @return all Rock, Paper, Scissors game rounds parsed from the file
     */
    auto parseFilePuzzleOne(const std::filesystem::path &inputFilePath) -> Input;

    /**
     * Parse the file one round at a time, providing each one to a specified handler, using puzzle one logic.
     *
     * @param inputFilePath path to read from
     * @param handleRoundCallback callback to process each parsed Round
     */
    auto parseFilePuzzleOne(const std::filesystem::path &inputFilePath,
                            const HandleRoundCallbackFunction &&handleRoundCallback) -> void;

    /**
     * Parse the complete file, using puzzle two logic.
     *
     * @param inputFilePath path to read from
     * @return all Rock, Paper, Scissors game rounds parsed from the file
     */
    auto parseFilePuzzleTwo(const std::filesystem::path &inputFilePath) -> Input;

    /**
     * Parse the file one round at a time, providing each one to a specified handler, using puzzle two logic.
     *
     * @param inputFilePath path to read from
     * @param handleRoundCallback callback to process each parsed Round
     */
    auto parseFilePuzzleTwo(const std::filesystem::path &inputFilePath,
                            const HandleRoundCallbackFunction &&handleRoundCallback) -> void;

} // AdventOfCode::DayTwo::Parser

#endif //ADVENT_OF_CODE_2022_CPP_DAYTWOPARSER_H
