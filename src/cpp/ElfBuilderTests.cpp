//
// Created by Aidan Nagorcka-Smith on 28/12/2022.
//

#include <gtest/gtest.h>

#include "Elf.h"
#include "ElfBuilder.h"

namespace AdventOfCode {

    TEST(ElfBuilder, BuilderCreation) {
        ElfBuilder builder{};
        const auto elf = builder.build();
        EXPECT_EQ(0, elf.carriedFood().size());
    }

    TEST(ElfBuilder, BuilderAddOneFood) {
        ElfBuilder builder{};

        const auto elf = builder.addFood(Food{10}).build();

        EXPECT_EQ(1, elf.carriedFood().size());
        EXPECT_EQ(10, elf.carriedFood().at(0).calories());
    }

    TEST(ElfBuilder, BuilderAddTwoFood) {
        ElfBuilder builder{};

        const auto elf = builder
                .addFood(Food{10})
                .addFood(Food{20})
                .build();

        EXPECT_EQ(2, elf.carriedFood().size());
        EXPECT_EQ(10, elf.carriedFood().at(0).calories());
        EXPECT_EQ(20, elf.carriedFood().at(1).calories());
    }

    TEST(ElfBuilder, BuilderAddThreeFood) {
        ElfBuilder builder{};

        const auto elf = builder
                .addFood(Food{10})
                .addFood(Food{20})
                .addFood(Food{30})
                .build();

        EXPECT_EQ(3, elf.carriedFood().size());
        EXPECT_EQ(10, elf.carriedFood().at(0).calories());
        EXPECT_EQ(20, elf.carriedFood().at(1).calories());
        EXPECT_EQ(30, elf.carriedFood().at(2).calories());
    }

    TEST(ElfBuilder, BuilderCanBeReused) {
        ElfBuilder builder{};

        const auto elfOne = builder.addFood(Food{100}).build();
        const auto elfTwo = builder.build();

        EXPECT_EQ(1, elfTwo.carriedFood().size());
    }

}