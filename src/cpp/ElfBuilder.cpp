//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#include "ElfBuilder.h"

#include "Elf.h"

namespace AdventOfCode {

    ElfBuilder ElfBuilder::addFood(const Food &food) {
        carriedFood_.push_back(food);
        return *this;
    }

    Elf ElfBuilder::build() {
        return Elf{carriedFood_};
    }

} // AdventOfCode