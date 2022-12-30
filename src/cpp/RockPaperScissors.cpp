//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo::RockPaperScissors {

    int pointValueForSelection(const Selection &selection) {
        switch (selection) {
            case kRock:
                return 1;
            case kPaper:
                return 2;
            case kScissors:
                return 3;
        }
    }

    Round::Round(const Selection &playerOne, const Selection &playerTwo) : playerOne_(playerOne), playerTwo_(playerTwo) {}

    Selection Round::playerOneSelection() const {
        return playerOne_;
    }

    Selection Round::playerTwoSelection() const {
        return playerTwo_;
    }
}
