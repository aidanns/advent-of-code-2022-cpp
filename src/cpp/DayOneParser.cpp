//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include "DayOneParser.h"

#include <iostream>

#include "InputFileReader.h"

namespace AdventOfCode::DayOne::Parser {

    std::vector<Elf> parseFile(const std::string &inputFilePath) {
        std::vector<Elf> parsedElves{};
        parseFile(inputFilePath, [&](const auto &elf) {
            parsedElves.push_back(elf);
        });
        return parsedElves;
    }

    void parseFile(const std::string &inputFilePath, const HandleElfCallbackFunction &&handleElfCallback) {

        auto elfBuilder = Elf::builder();

        InputFileReader::parseFile(inputFilePath, [&](const auto &line) -> void {
            if (!line.empty()) {
                // TODO(aidanns): Handle the case where we have a malformed line.
                elfBuilder.addFood(Food{std::stoi(line)});
            } else {
                handleElfCallback(elfBuilder.build());
                elfBuilder.reset();
            }
        });
    }
} // AdventOfCode::DayOne::Parser