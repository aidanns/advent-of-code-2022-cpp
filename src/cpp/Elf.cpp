//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include <vector>

#include "Elf.h"

namespace AdventOfCode {

    std::vector<AdventOfCode::Food> Elf::carriedFood() const {
        return carriedFood_;
    };

    ElfBuilder Elf::builder()  {
        return ElfBuilder{};
    }
}