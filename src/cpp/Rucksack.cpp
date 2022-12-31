//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "Rucksack.h"

#include <algorithm>
#include <utility>

namespace AdventOfCode::DayThree {
    Rucksack::Compartment::Compartment(std::vector<Item> &items) : items_(std::move(items)) {}

    auto Rucksack::Compartment::contains(const Item &item) const -> bool {
        if (std::find(items_.begin(), items_.end(), item) != items_.end()) {
            return true;
        } else {
            return false;
        }
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

    auto Rucksack::allUniqueItems() const -> std::set<Item> {
        std::set<Item> items;
        for (const auto &item : compartmentOne_.items()) {
            items.insert(item);
        }
        for (const auto &item : compartmentTwo_.items()) {
            items.insert(item);
        }
        return items;
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

    auto Rucksack::Builder::build() -> Rucksack {
        return {Rucksack::Compartment(compartmentOneContent_),
                Rucksack::Compartment(compartmentTwoContent_)};
    }

    void Rucksack::Builder::reset() {
        compartmentOneContent_ = std::vector<Item>();
        compartmentTwoContent_ = std::vector<Item>();
    }
} // AdventOfCode::DayThree