//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef ROCK_PAPER_SCISSORS_H
#define ROCK_PAPER_SCISSORS_H

namespace AdventOfCode::DayTwo::RockPaperScissors {

    /**
     * The selection made by each player in a single round of the game.
     */
    enum Selection {
        kRock,
        kPaper,
        kScissors
    };

    /**
     * The result from a round.
     */
    enum Result {
        kPlayerOneWin,
        kDraw,
        kPlayerTwoWin
    };

    /**
     * Represents a round of the game, with a selection made by two separate players.
     */
    class Round {
    public:
        Round(const Selection &playerOne, const Selection &playerTwo);
        [[nodiscard]] Selection playerOneSelection() const;
        [[nodiscard]] Selection playerTwoSelection() const;
    private:
        const Selection playerOne_;
        const Selection playerTwo_;
    };

    /**
     * Returns the result from a round.
     *
     * @param round the round to assess
     * @return the result of the round
     */
    Result resultFromRound(const Round &round);
}

#endif // ROCK_PAPER_SCISSORS_H
