//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include "DayOneParser.h"

#include <iostream>

namespace AdventOfCode::DayOne::Parser {

    std::vector<Elf> parseFile(const std::string &inputFilePath) {
        std::vector<Elf> parsedElves{};
        parseFile(inputFilePath, [&](const auto &elf) {
            parsedElves.push_back(elf);
        });
        return parsedElves;
    }

    void parseFile(const std::string &inputFilePath, std::function<void(Elf)> &&handleElfCallback) {
        std::ifstream infile(inputFilePath);
        std::string line;
        auto elfBuilder = Elf::builder();

        // Get the input from the input file until EOF.
        while (std::getline(infile, line)) {
            if (!line.empty()) {
                // TODO(aidanns): Handle the case where we have a malformed line.
                elfBuilder.addFood(Food{std::stoi(line)});
            } else {
                handleElfCallback(elfBuilder.build());
                elfBuilder = Elf::builder();
            }
        }
    }
} // AdventOfCode::DayOne::Parser