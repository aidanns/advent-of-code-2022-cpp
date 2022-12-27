//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include <vector>

#include "Elf.h"

namespace AdventOfCode {

    std::vector<AdventOfCode::Food> Elf::carriedFood() const {
        return carriedFood_;
    };

    int Elf::totalCarriedCalories() const {
        int total = 0;
        for (auto const & food : carriedFood_) {
            total += food.calories();
        }
        return total;
    }

    ElfBuilder Elf::builder()  {
        return ElfBuilder{};
    }
}