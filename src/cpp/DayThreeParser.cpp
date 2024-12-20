//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayThreeParser.h"

#include "InputFileReader.h"

namespace AdventOfCode::DayThree::Parser {

    auto parseFilePuzzleOne(const std::filesystem::path &inputFilePath) -> Input {
        std::vector<Rucksack> rucksacks;
        parseFile(inputFilePath, [&](auto &&rucksack) {
            rucksacks.push_back(std::forward<decltype(rucksack)>(rucksack));
        });
        return rucksacks;
    }

    /**
     * Returns the priority for a given char, or -1 if that char is not assigned a priority.
     */
    auto priorityForCharValue(char value) noexcept-> int {
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
    auto itemTypeForValidChar(char c) noexcept -> ItemType {
        return static_cast<ItemType>(priorityForCharValue(c));
    }

    auto parseFile(const std::filesystem::path &inputFilePath,
                   const HandleRucksackCallbackFunction &&handleRucksackCallbackFunction) -> void {
        Rucksack::Builder builder = Rucksack::Builder();

        auto lineIsValid = [](const auto &line) -> bool {
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

        InputFileReader::readLines(inputFilePath, [&](auto &&line) -> void {
            // Validate that the line is valid.
            if (!lineIsValid(line)) {
                return;
            }

            // Assume valid line from this point onwards.
            for (size_t i = 0; i < line.length() / 2; i++) {
                builder.withCompartmentOneContent(Item(itemTypeForValidChar(line.at(i))));
            }
            for (size_t i = line.length() / 2; i < line.length(); i++) {
                builder.withCompartmentTwoContent(Item(itemTypeForValidChar(line.at(i))));
            }

            handleRucksackCallbackFunction(builder.build());
        });
    }
}