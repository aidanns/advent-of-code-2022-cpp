//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "Rucksack.h"

#include <algorithm>
#include <utility>

namespace AdventOfCode::DayThree {
    Rucksack::Compartment::Compartment(std::vector<Item> &items) : items_(std::move(items)) {}

    auto Rucksack::Compartment::contains(const Item &item) const -> bool {
        // TODO(aidanns): Improve this performance.
        for (const auto &containedItem : items_) {
            if (containedItem.priority() == item.priority()) {
                return true;
            }
        }
        return false;
    }

    auto Rucksack::Compartment::items() const -> std::vector<Item> {
        return items_;
    }

    Rucksack::Rucksack(Rucksack::Compartment compartmentOne, Rucksack::Compartment compartmentTwo)
        : compartmentOne_(std::move(compartmentOne)), compartmentTwo_(std::move(compartmentTwo)) {}

    auto Rucksack::compartmentOne() const -> Rucksack::Compartment {
        return compartmentOne_;
    }

    auto Rucksack::compartmentTwo() const -> Rucksack::Compartment {
        return compartmentTwo_;
    }

    auto Rucksack::builder() -> Builder {
        return {};
    }

    Rucksack::Builder Rucksack::Builder::withCompartmentOneContent(const Item &item) {
        compartmentOneContent_.push_back(item);
        return *this;
    }

    Rucksack::Builder Rucksack::Builder::withCompartmentTwoContent(const Item &item) {
        compartmentTwoContent_.push_back(item);
        return *this;
    }

    Rucksack Rucksack::Builder::build() {
        return Rucksack(Rucksack::Compartment(compartmentOneContent_),
                        Rucksack::Compartment(compartmentTwoContent_));
    }

    void Rucksack::Builder::reset() {
        compartmentOneContent_ = std::vector<Item>();
        compartmentTwoContent_ = std::vector<Item>();
    }
} // AdventOfCode::DayThree