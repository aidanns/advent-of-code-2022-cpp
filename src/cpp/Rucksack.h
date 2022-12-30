//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#ifndef RUCKSACK_H
#define RUCKSACK_H

#include <vector>

#include "Item.h"

namespace AdventOfCode::DayThree {

    class Rucksack {
    public:
        class Compartment {
        public:
            explicit Compartment(std::vector<Item> &items);
            [[nodiscard]] auto contains(const Item &item) const -> bool;
            [[nodiscard]] auto items() const -> std::vector<Item>;
        private:
            const std::vector<Item> items_;
        };

        class Builder {
        public:
            Builder withCompartmentOneContent(const Item &item);
            Builder withCompartmentTwoContent(const Item &item);

            Rucksack build();
            void reset();
        private:
            std::vector<Item> compartmentOneContent_;
            std::vector<Item> compartmentTwoContent_;
        };

        Rucksack(Compartment compartmentOne, Compartment compartmentTwo);
        [[nodiscard]] auto compartmentOne() const -> Compartment;
        [[nodiscard]] auto compartmentTwo() const -> Compartment;

        static auto builder() -> Builder;
    private:
        Compartment compartmentOne_;
        Compartment compartmentTwo_;
    };

} // AdventOfCode::DayThree

#endif // RUCKSACK_H
