//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#include "ElfBuilder.h"

#include <vector>

#include "Elf.h"

namespace AdventOfCode {

    auto ElfBuilder::addFood(Food &&food) -> ElfBuilder & {
        carriedFood_.push_back(std::move(food));
        return *this;
    }

    auto ElfBuilder::build() -> Elf {
        Elf e = Elf{carriedFood_};
        reset();
        return e;
    }

    void ElfBuilder::reset() {
        carriedFood_ = std::vector<Food>{};
    }

} // AdventOfCode