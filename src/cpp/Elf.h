//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#ifndef ELF_H
#define ELF_H

#include <utility>
#include <vector>

#include "ElfBuilder.h"
#include "Food.h"

namespace AdventOfCode {

    class ElfBuilder;

    class Elf {
    public:
        explicit Elf(std::vector<Food> food) : carriedFood_(std::move(food)) {}

        [[nodiscard]] std::vector<AdventOfCode::Food> carriedFood() const;
        [[nodiscard]] int totalCarriedCalories() const;

        static ElfBuilder builder();

    private:
        const std::vector<Food> carriedFood_;
    };

}

#endif // ELF_H
