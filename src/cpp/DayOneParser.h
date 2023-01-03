//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#ifndef DAY_ONE_PARSER_H
#define DAY_ONE_PARSER_H

#include <filesystem>
#include <functional>
#include <vector>
#include <fstream>

#include "Elf.h"

namespace AdventOfCode::DayOne::Parser {

    using HandleElfCallbackFunction = std::function<void(Elf &&)>;

    const auto kDayOneInputFilePath = "../src/data/input_day_one.txt";

    /**
     * Parse the complete file.
     *
     * @param inputFilePath path to read from
     * @return all Elf's parsed from the file
     */
    auto parseFile(const std::filesystem::path &inputFilePath) -> std::vector<Elf>;

    /**
     * Parse the file one elf at a time, providing each one to a specified handler.
     *
     * @param inputFilePath path to read from
     * @param handleElfCallback callback to process each parsed Elf
     */
    auto parseFile(const std::filesystem::path &inputFilePath,
                   const HandleElfCallbackFunction &&handleElfCallback) -> void;
} // AdventOfCode::DayOne::Parser

#endif // DAY_ONE_PARSER_H
