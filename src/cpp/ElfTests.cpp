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

    TEST(Elf, TotalCaloriesNoFood) {
        Elf elf = Elf::builder().build();
        EXPECT_EQ(0, elf.totalCarriedCalories());
    }

    TEST(Elf, TotalCaloriesOneFood) {
        Elf elf = Elf::builder()
                .addFood(Food{10})
                .build();
        EXPECT_EQ(10, elf.totalCarriedCalories());
    }

    TEST(Elf, TotalCaloriesTwoFood) {
        Elf elf = Elf::builder()
                .addFood(Food{10})
                .addFood(Food{20})
                .build();
        EXPECT_EQ(30, elf.totalCarriedCalories());
    }

    TEST(Elf, TotalCaloriesThreeFood) {
        Elf elf = Elf::builder()
                .addFood(Food{10})
                .addFood(Food{20})
                .addFood(Food{30})
                .build();
        EXPECT_EQ(60, elf.totalCarriedCalories());
    }
}