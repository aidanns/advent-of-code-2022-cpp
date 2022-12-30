//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayThreeParser.h"

#include "InputFileReader.h"

namespace AdventOfCode::DayThree::Parser {

    std::vector<Rucksack> parseFilePuzzleOne(const std::string &inputFilePath) {
        std::vector<Rucksack> rucksacks;
        parseFilePuzzleOne(inputFilePath, [&](const auto &rucksack) {
            rucksacks.push_back(rucksack);
        });
        return rucksacks;
    }

    void parseFilePuzzleOne(const std::string &inputFilePath,
                            const HandleRucksackCallbackFunction &&handleRucksackCallbackFunction) {

        Rucksack::Builder builder = Rucksack::Builder();

        InputFileReader::readLines(inputFilePath, [&](const std::string &line) {
            for (int i = 0; i < line.length() / 2; i++) {
                builder.withCompartmentOneContent(Item(line.at(i)));
            }

            for (int i = line.length() / 2; i < line.length(); i++) {
                builder.withCompartmentTwoContent(Item(line.at(i)));
            }

            handleRucksackCallbackFunction(builder.build());
            builder.reset();
        });
    }
}