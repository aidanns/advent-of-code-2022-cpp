//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef RUCKSACK_H
#define RUCKSACK_H

#include <set>
#include <vector>

#include "Item.h"

namespace AdventOfCode::DayThree {

    class Rucksack {
    public:
        class Compartment {
        public:
            Compartment(Compartment &&other) noexcept;
            Compartment(const Compartment &other) noexcept;
            explicit Compartment(std::vector<Item> &&items);
            [[nodiscard]] auto contains(const Item &item) const -> bool;
            [[nodiscard]] auto items() const -> const std::vector<Item> &;
        private:
            std::vector<Item> items_;
        };

        class Builder {
        public:
            auto withCompartmentOneContent(const Item &item) -> Builder &;
            auto withCompartmentOneContent(Item &&item) -> Builder &;
            auto withCompartmentTwoContent(const Item &item) -> Builder &;
            auto withCompartmentTwoContent(Item &&item) -> Builder &;

            auto build() -> Rucksack;
            auto reset() -> void;
        private:
            std::vector<Item> compartmentOneContent_;
            std::vector<Item> compartmentTwoContent_;
        };

        Rucksack(const Rucksack &other) noexcept;
        Rucksack(Rucksack &&other) noexcept;
        Rucksack(Compartment &&compartmentOne, Compartment &&compartmentTwo) noexcept;

        [[nodiscard]] auto compartmentOne() const -> const Compartment &;
        [[nodiscard]] auto compartmentTwo() const -> const Compartment &;
        [[nodiscard]] auto allUniqueItems() const -> std::set<Item>;

        static auto builder() -> Builder;
    private:
        Compartment compartmentOne_;
        Compartment compartmentTwo_;
    };

} // AdventOfCode::DayThree

#endif // RUCKSACK_H
