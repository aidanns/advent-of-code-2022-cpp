//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef DAY_THREE_PARSER_H
#define DAY_THREE_PARSER_H

#include <string>
#include <vector>

#include "Rucksack.h"

namespace AdventOfCode::DayThree::Parser {

    using HandleRucksackCallbackFunction = std::function<void(const Rucksack &)>;

    const std::string kDayThreeInputFilePath = "../src/data/input_day_three.txt";

    /**
     * Parse the complete file.
     *
     * @param inputFilePath path to read from
     * @return all rucksack configurations parsed from the file
     */
    std::vector<Rucksack> parseFilePuzzleOne(const std::string &inputFilePath);

    /**
     * Parse the file one round at a time, providing each one to a specified handler.
     *
     * @param inputFilePath path to read from
     * @param handleRucksackCallbackFunction callback to process each parsed Rucksack
     */
    void parseFile(const std::string &inputFilePath, const HandleRucksackCallbackFunction &&handleRucksackCallbackFunction);
}

#endif // DAY_THREE_PARSER_H
