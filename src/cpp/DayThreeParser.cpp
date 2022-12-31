//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayThreeParser.h"

#include <ranges>

#include "InputFileReader.h"

namespace AdventOfCode::DayThree::Parser {

    std::vector<Rucksack> parseFilePuzzleOne(const std::string &inputFilePath) {
        std::vector<Rucksack> rucksacks;
        parseFilePuzzleOne(inputFilePath, [&](const auto &rucksack) {
            rucksacks.push_back(rucksack);
        });
        return rucksacks;
    }

    /**
     * Returns the priority for a given char, or -1 if that char is not assigned a priority.
     */
    int priorityForCharValue(char value) noexcept {
        // Lower case chars have ASCII values 96 - 122, we want to map in to 1 - 26.
        if (value >= 'a' && value <= 'z') {
            return static_cast<int>(value) - 96;
        }

        // Upper case chars have ASCII values 65 - 90, we want to map in to 27 - 52.
        if (value >= 'A' && value <= 'Z') {
            return static_cast<int>(value) - 38;
        }

        // TODO(aidanns): Better error handling here.
        return -1;
    }

    /**
     * Returns an ItemType for a given char. Performs no error handling, so must only be called with valid chars.
     */
    ItemType itemTypeForValidChar(char c) noexcept {
        return static_cast<ItemType>(priorityForCharValue(c));
    }

    void parseFilePuzzleOne(const std::string &inputFilePath,
                            const HandleRucksackCallbackFunction &&handleRucksackCallbackFunction) {

        Rucksack::Builder builder = Rucksack::Builder();

        auto lineIsValid = [](const std::string &line) -> bool {
            // Valid chars are a-z and A-Z.
            auto charIsValid = [](const char c) {
                return priorityForCharValue(c) != -1;
            };

            for (char c : line) {
                if (!charIsValid(c)) {
                    return false;
                }
            }

            // Must have a even number of chars so that we can split the line in to two equal parts.
            return line.length() % 2 == 0;
        };

        InputFileReader::readLines(inputFilePath, [&](const std::string &line) {

            if (!lineIsValid(line)) {
                return;
            }

            for (int i = 0; i < line.length() / 2; i++) {
                builder.withCompartmentOneContent(Item(itemTypeForValidChar(line.at(i))));
            }

            for (int i = line.length() / 2; i < line.length(); i++) {
                builder.withCompartmentTwoContent(Item(itemTypeForValidChar(line.at(i))));
            }

            handleRucksackCallbackFunction(builder.build());
            builder.reset();
        });
    }
}