//
// Created by Aidan Nagorcka-Smith on 27/12/2022.
//

#include <gtest/gtest.h>

#include "Elf.h"

namespace AdventOfCode {

    TEST(Elf, ManualCreation) {
        Elf elf{std::vector<Food>{}};
        EXPECT_EQ(0, elf.carriedFood().size());
    }

    TEST(Elf, BuilderCreation) {
        Elf elf = Elf::builder().build();
        EXPECT_EQ(0, elf.carriedFood().size());
    }
}