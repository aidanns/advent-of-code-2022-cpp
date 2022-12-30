//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "Rucksack.h"

namespace AdventOfCode::DayThree {

    TEST(Rucksack, creation) {
        auto rucksack = Rucksack::builder()
                .withCompartmentOneContent(Item('a'))
                .withCompartmentOneContent(Item('b'))
                .withCompartmentTwoContent(Item('c'))
                .withCompartmentTwoContent(Item('b'))
                .build();

        EXPECT_EQ(1, rucksack.compartmentOne().items().at(0).priority());
        EXPECT_EQ(2, rucksack.compartmentOne().items().at(1).priority());
        EXPECT_EQ(3, rucksack.compartmentTwo().items().at(0).priority());
        EXPECT_EQ(2, rucksack.compartmentTwo().items().at(1).priority());
    }

    TEST(Rucksack, contains) {
        auto rucksack = Rucksack::builder()
                .withCompartmentOneContent(Item('a'))
                .build();

        EXPECT_EQ(true, rucksack.compartmentOne().contains(Item('a')));
        EXPECT_EQ(false, rucksack.compartmentOne().contains(Item('b')));
    }
}