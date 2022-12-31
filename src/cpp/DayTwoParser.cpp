//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayTwoParser.h"

#include "InputFileReader.h"

namespace AdventOfCode::DayTwo::Parser {

    auto parseFilePuzzleOne(const std::filesystem::path &inputFilePath) -> Input {
        std::vector<RockPaperScissors::Round> parsedRounds;
        parseFilePuzzleOne(inputFilePath, [&](auto &&round) -> void {
            parsedRounds.push_back(std::forward<decltype(round)>(round));
        });
        return parsedRounds;
    }

    auto parseFilePuzzleOne(const std::filesystem::path &inputFilePath,
                            const HandleRoundCallbackFunction &&handleRoundCallback) -> void {
        InputFileReader::readLines(inputFilePath, [&](auto &&line) -> void {
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

    auto parseFilePuzzleTwo(const std::filesystem::path &inputFilePath) -> Input {
        std::vector<RockPaperScissors::Round> parsedRounds;
        parseFilePuzzleTwo(inputFilePath, [&](auto &&round) {
            parsedRounds.push_back(std::forward<decltype(round)>(round));
        });
        return parsedRounds;
    }

    auto selectionThatWinsAgainst(const RockPaperScissors::Selection &selection) -> RockPaperScissors::Selection {
        switch (selection) {
            case RockPaperScissors::Selection::kScissors:
                return RockPaperScissors::Selection::kRock;
            case RockPaperScissors::Selection::kRock:
                return RockPaperScissors::Selection::kPaper;
            case RockPaperScissors::Selection::kPaper:
                return RockPaperScissors::Selection::kScissors;
        }
    }

    auto selectionThatDrawsAgainst(const RockPaperScissors::Selection &selection) -> RockPaperScissors::Selection {
        return selection;
    }

    auto selectionThatLosesAgainst(const RockPaperScissors::Selection &selection) -> RockPaperScissors::Selection {
        switch (selection) {
            case RockPaperScissors::Selection::kScissors:
                return RockPaperScissors::Selection::kPaper;
            case RockPaperScissors::Selection::kRock:
                return RockPaperScissors::Selection::kScissors;
            case RockPaperScissors::Selection::kPaper:
                return RockPaperScissors::Selection::kRock;
        }
    }

    auto parseFilePuzzleTwo(const std::filesystem::path &inputFilePath,
                            const HandleRoundCallbackFunction &&handleRoundCallback)-> void {
        InputFileReader::readLines(inputFilePath, [&](auto &&line) -> void {
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
                        playerTwoSelection = selectionThatLosesAgainst(playerOneSelection);
                        break;
                    case 'Y':
                        playerTwoSelection = selectionThatDrawsAgainst(playerOneSelection);
                        break;
                    case 'Z':
                        playerTwoSelection = selectionThatWinsAgainst(playerOneSelection);
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