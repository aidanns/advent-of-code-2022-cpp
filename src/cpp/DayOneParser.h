//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#ifndef DAY_ONE_PARSER_H
#define DAY_ONE_PARSER_H

#include <vector>
#include <fstream>

#include "Elf.h"

namespace AdventOfCode::DayOne::Parser {

    using HandleElfCallbackFunction = std::function<void(const Elf &)>;

    const std::string kDayOneInputFilePath = "../src/data/day_one_puzzle_one.txt";

    /**
     * Parse the complete file.
     *
     * @param inputFilePath path to read from
     * @return all Elf's parsed from the file
     */
    std::vector<Elf> parseFile(const std::string &inputFilePath);

    /**
     * Parse the file one elf at a time, providing each one to a specified handler.
     *
     * @param inputFilePath path to read from
     * @param handleElfCallback callback to process each parsed Elf
     */
    void parseFile(const std::string &inputFilePath, const HandleElfCallbackFunction &&handleElfCallback);
} // AdventOfCode::DayOne::Parser

#endif // DAY_ONE_PARSER_H
