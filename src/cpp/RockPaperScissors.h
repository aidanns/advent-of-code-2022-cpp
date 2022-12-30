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
     * Returns the points awarded to a player for making a given selection.
     *
     * @param selection the selection made
     * @return the point value awarded as a result
     */
    int pointValueForSelection(const Selection &selection);
}

#endif // ROCK_PAPER_SCISSORS_H
