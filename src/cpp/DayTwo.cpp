//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "DayTwo.h"

#include <iostream>

#include "DayTwoParser.h"
#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo {

    int pointValueForSelection(const RockPaperScissors::Selection &selection) {
        switch (selection) {
            case RockPaperScissors::Selection::kRock:
                return 1;
            case RockPaperScissors::Selection::kPaper:
                return 2;
            case RockPaperScissors::Selection::kScissors:
                return 3;
        }
    }

    int playerTwoPointValueForResult(const RockPaperScissors::Result &result) {
        switch (result) {
            case RockPaperScissors::Result::kPlayerTwoWin:
                return 6;
            case RockPaperScissors::Result::kDraw:
                return 3;
            case RockPaperScissors::Result::kPlayerOneWin:
                return 0;
        }
    }

    int playerTwoScoreForRound(const RockPaperScissors::Round &round) {
        int scoreFromSelection = pointValueForSelection(round.playerTwoSelection());
        int scoreFromResult = playerTwoPointValueForResult(RockPaperScissors::resultFromRound(round));
        return scoreFromResult + scoreFromSelection;
    }

    int puzzleSolution(const Input &input) {
        int totalScore = 0;
        for (const auto &round : input) {
            totalScore += playerTwoScoreForRound(round);
        }
        return totalScore;
    }

    void run() {
        Input puzzleOneInput = Parser::parseFilePuzzleOne(Parser::kDayTwoInputFilePath);
        std::cout << "Day 2 - Puzzle 1" << std::endl
                  << "My score in the Rock, Paper, Scissors tournament: " << puzzleSolution(puzzleOneInput) << std::endl;
        Input puzzleTwoInput = Parser::parseFilePuzzleTwo(Parser::kDayTwoInputFilePath);
        std::cout << "Day 2 - Puzzle 2" << std::endl
                  << "My score in the Rock, Paper, Scissors tournament: " << puzzleSolution(puzzleTwoInput) << std::endl;
    }
}
