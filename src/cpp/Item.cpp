//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "Item.h"

#include <type_traits>

namespace AdventOfCode::DayThree {

    int priorityForItemType(ItemType type) {
        return static_cast<typename std::underlying_type<ItemType>::type>(type);
    }

    Item::Item(ItemType type) : priority_(priorityForItemType(type)) {}

    auto Item::priority() const -> int {
        return priority_;
    }
}

