//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include "DayOneParser.h"

#include <iostream>

namespace AdventOfCode::DayOneParser {

    std::vector<Elf> parseFile(const std::string &inputFilePath) {
        // TODO(aidanns): Handle the case where the path isn't a file or can't be read.

        std::vector<Elf> parsedElves{};

        std::ifstream infile(inputFilePath);
        std::string line;
        auto elfBuilder = Elf::builder();

        // Get the input from the input file until EOF
        while (std::getline(infile, line)) {

            if (!line.empty()) {
                // TODO(aidanns): Handle the case where we have a malformed line.
                elfBuilder.addFood(Food{std::stoi(line)});
            } else {
                parsedElves.push_back(elfBuilder.build());
                elfBuilder = Elf::builder();
            }
        }

        return parsedElves;
    }
} // AdventOfCode::DayOneParser