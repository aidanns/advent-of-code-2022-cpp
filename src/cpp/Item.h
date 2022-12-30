//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef ITEM_H
#define ITEM_H

namespace AdventOfCode::DayThree {
    class Item {
    public:
        explicit Item(char value);
        [[nodiscard]] auto priority() const -> int;
    private:
        const int priority_;
    };
}

#endif // ITEM_H
