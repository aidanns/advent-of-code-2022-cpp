//
// Created by Aidan Nagorcka-Smith on 30/12/2022.
//

#include <gtest/gtest.h>
#include <nanobench.h>

#include "Item.h"

namespace AdventOfCode::DayTwo::Item {

    TEST(Item, creation) {
        EXPECT_EQ(1, AdventOfCode::DayThree::Item{'a'}.priority());
        EXPECT_EQ(2, AdventOfCode::DayThree::Item{'b'}.priority());
        EXPECT_EQ(26, AdventOfCode::DayThree::Item{'z'}.priority());
        EXPECT_EQ(27, AdventOfCode::DayThree::Item{'A'}.priority());
        EXPECT_EQ(28, AdventOfCode::DayThree::Item{'B'}.priority());
        EXPECT_EQ(52, AdventOfCode::DayThree::Item{'Z'}.priority());
    }
}