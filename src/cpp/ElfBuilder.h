//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#ifndef ELF_BUILDER_H
#define ELF_BUILDER_H

#include <vector>

#include "Elf.h"
#include "Food.h"

namespace AdventOfCode {

    class Elf;

    class ElfBuilder {
    public:
        explicit ElfBuilder() = default;

        auto addFood(Food &&food) -> ElfBuilder &;

        auto build() -> Elf;

        /**
         * Resets the builder, equivalent to creation of a new builder.
         */
        void reset();
    private:
        std::vector<Food> carriedFood_;
    };

} // AdventOfCode

#endif // ELF_BUILDER_H
