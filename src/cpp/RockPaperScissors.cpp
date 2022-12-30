//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "RockPaperScissors.h"

namespace AdventOfCode::DayTwo::RockPaperScissors {

    Result resultFromRound(const Round &round) {
        switch (round.playerOneSelection()) {
            case kRock:
                switch (round.playerTwoSelection()) {
                    case kRock:
                        return kDraw;
                    case Selection::kPaper:
                        return kPlayerTwoWin;
                    case Selection::kScissors:
                        return kPlayerOneWin;
                }
            case kPaper:
                switch (round.playerTwoSelection()) {
                    case kRock:
                        return kPlayerOneWin;
                    case Selection::kPaper:
                        return kDraw;
                    case Selection::kScissors:
                        return kPlayerTwoWin;
                }
            case kScissors:
                switch (round.playerTwoSelection()) {
                    case kRock:
                        return kPlayerTwoWin;
                    case Selection::kPaper:
                        return kPlayerOneWin;
                    case Selection::kScissors:
                        return kDraw;
                }
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
