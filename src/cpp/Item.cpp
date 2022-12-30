//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "Item.h"

namespace AdventOfCode::DayThree {

    int priorityForItemValue(char value) noexcept {
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

    Item::Item(char value) : priority_(priorityForItemValue(value)) {}

    auto Item::priority() const -> int {
        return priority_;
    }
}

