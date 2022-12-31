//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "Item.h"

namespace AdventOfCode::DayThree {

    TEST(Item, creation) {
        EXPECT_EQ(1, Item{ItemType::a}.priority());
        EXPECT_EQ(2, Item{ItemType::b}.priority());
        EXPECT_EQ(26, Item{ItemType::z}.priority());
        EXPECT_EQ(27, Item{ItemType::A}.priority());
        EXPECT_EQ(28, Item{ItemType::B}.priority());
        EXPECT_EQ(52, Item{ItemType::Z}.priority());
    }
}