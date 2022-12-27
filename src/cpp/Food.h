//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#ifndef FOOD_H
#define FOOD_H

namespace AdventOfCode {

    class Food {
    public:
        explicit Food(const int calories) : calories_(calories) {}

        [[nodiscard]] int calories() const {
            return calories_;
        }
    private:
        const int calories_;
    };

} // AdventOfCode

#endif // FOOD_H
