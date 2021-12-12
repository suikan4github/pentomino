#include "gtest/gtest.h"
#include "utility.hpp"
#include <stdexcept>

TEST(Utility, InitializeMap)
{
    Map map;

    map[0][0] = '0';
    InitializeMap(map);

    EXPECT_EQ(map[0][0], unused);
    EXPECT_EQ(map[xsize - 1][0], unused);
    EXPECT_EQ(map[0][ysize - 1], unused);
    EXPECT_EQ(map[xsize - 1][ysize - 1], unused);
}
