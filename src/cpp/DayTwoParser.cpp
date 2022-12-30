//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayTwoParser.h"

#include <fstream>

#include "InputFileReader.h"

namespace AdventOfCode::DayTwo::Parser {

    std::vector<RockPaperScissors::Round> parseFile(const std::string &inputFilePath) {
        std::vector<RockPaperScissors::Round> parsedRounds{};
        parseFile(inputFilePath, [&](const auto &round) {
            parsedRounds.push_back(round);
        });
        return parsedRounds;
    }

    void parseFile(const std::string &inputFilePath, const HandleRoundCallbackFunction &&handleRoundCallback) {
        InputFileReader::readLines(inputFilePath, [&](const std::string &line) -> void {
            if (line.size() == 3) {

                RockPaperScissors::Selection playerOneSelection;
                RockPaperScissors::Selection playerTwoSelection;

                switch (line.at(0)) {
                    case 'A':
                        playerOneSelection = RockPaperScissors::Selection::kRock;
                        break;
                    case 'B':
                        playerOneSelection = RockPaperScissors::Selection::kPaper;
                        break;
                    case 'C':
                        playerOneSelection = RockPaperScissors::Selection::kScissors;
                        break;
                    default:
                        // Skip lines that have malformed components.
                        // TODO(aidanns): Log a warn message that we're dropping a line here.
                        return;
                }

                switch (line.at(2)) {
                    case 'X':
                        playerTwoSelection = RockPaperScissors::Selection::kRock;
                        break;
                    case 'Y':
                        playerTwoSelection = RockPaperScissors::Selection::kPaper;
                        break;
                    case 'Z':
                        playerTwoSelection = RockPaperScissors::Selection::kScissors;
                        break;
                    default:
                        // Skip lines that have malformed components.
                        // TODO(aidanns): Log a warn message that we're dropping a line here.
                        return;
                }

                handleRoundCallback(RockPaperScissors::Round(playerOneSelection, playerTwoSelection));
            } else {
                // TODO(aidanns): Log a warn message that we're dropping a line here.
                return;
            }
        });
    }
} // AdventOfCode::DayTwo::Parser