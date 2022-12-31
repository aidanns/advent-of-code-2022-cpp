//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include "Rucksack.h"

#include <algorithm>
#include <utility>

namespace AdventOfCode::DayThree {

    Rucksack::Compartment::Compartment(Compartment &&other) noexcept : items_(std::move(other.items_)) {}
    Rucksack::Compartment::Compartment(const Compartment &other) noexcept = default;
    Rucksack::Compartment::Compartment(std::vector<Item> &items) : items_(std::move(items)) {}

    auto Rucksack::Compartment::contains(const Item &item) const -> bool {
        if (std::find(items_.begin(), items_.end(), item) != items_.end()) {
            return true;
        } else {
            return false;
        }
    }

    auto Rucksack::Compartment::items() const -> const std::vector<Item> & {
        return items_;
    }

    Rucksack::Rucksack(Rucksack::Compartment compartmentOne, Rucksack::Compartment compartmentTwo) noexcept
        : compartmentOne_(std::move(compartmentOne)), compartmentTwo_(std::move(compartmentTwo)) {}

    Rucksack::Rucksack(const Rucksack &other) noexcept = default;

    auto Rucksack::compartmentOne() const -> const Rucksack::Compartment & {
        return compartmentOne_;
    }

    auto Rucksack::compartmentTwo() const -> const Rucksack::Compartment & {
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

    auto Rucksack::Builder::withCompartmentOneContent(const Item &item) -> Rucksack::Builder & {
        compartmentOneContent_.push_back(item);
        return *this;
    }

    auto Rucksack::Builder::withCompartmentTwoContent(const Item &item) -> Rucksack::Builder & {
        compartmentTwoContent_.push_back(item);
        return *this;
    }

    auto Rucksack::Builder::build() -> Rucksack {
        Rucksack r = {Rucksack::Compartment(compartmentOneContent_),
                      Rucksack::Compartment(compartmentTwoContent_)};
        reset();
        return r;
    }

    void Rucksack::Builder::reset() {
        compartmentOneContent_ = std::vector<Item>();
        compartmentTwoContent_ = std::vector<Item>();
    }

    auto Rucksack::Builder::withCompartmentOneContent(Item &&item) -> Rucksack::Builder & {
        compartmentOneContent_.push_back(std::move(item));
        return *this;
    }

    auto Rucksack::Builder::withCompartmentTwoContent(Item &&item) -> Rucksack::Builder & {
        compartmentTwoContent_.push_back(std::move(item));
        return *this;
    }
} // AdventOfCode::DayThree