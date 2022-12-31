//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include "DayOneParser.h"

#include <iostream>

#include "InputFileReader.h"

namespace AdventOfCode::DayOne::Parser {

    std::vector<Elf> parseFile(const std::filesystem::path &inputFilePath) {
        std::vector<Elf> parsedElves{};
        parseFile(inputFilePath, [&](auto &&elf) {
            parsedElves.push_back(std::forward<decltype(elf)>(elf));
        });
        return parsedElves;
    }

    void parseFile(const std::filesystem::path &inputFilePath, const HandleElfCallbackFunction &&handleElfCallback) {

        auto elfBuilder = Elf::builder();

        InputFileReader::readLines(inputFilePath, [&](auto &&line) -> void {
            if (!line.empty()) {
                // TODO(aidanns): Handle the case where we have a malformed line.
                elfBuilder.addFood(Food{std::stoi(line)});
            } else {
                handleElfCallback(elfBuilder.build());
            }
        });
    }
} // AdventOfCode::DayOne::Parser