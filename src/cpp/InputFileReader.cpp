//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "InputFileReader.h"

#include <fstream>

namespace AdventOfCode::InputFileReader {

    void readLines(const std::filesystem::path &inputFilePath, const HandleLineCallbackFunction &&handleLine) {
        std::ifstream infile(inputFilePath);
        std::string line;

        // Get the input from the input file until EOF.
        while (std::getline(infile, line)) {
            handleLine(std::move(line));
        }
    }
} // AdventOfCode::InputFileReader