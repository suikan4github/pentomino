// Test cases for the Cell class

#include "gtest/gtest.h"
#include "cell.hpp"
#include <stdexcept>

TEST(Cell, EqOp)
{
    Cell a(1, 2);
    Cell b(1, 3);
    Cell c(2, 2);

    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == c);
    EXPECT_FALSE(c == a);

    EXPECT_TRUE(a == a);
}

TEST(Cell, NeOp)
{
    Cell a(1, 2);
    Cell b(1, 3);
    Cell c(2, 2);

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != c);
    EXPECT_TRUE(c != a);

    EXPECT_FALSE(a != a);
}

TEST(Cell, LtOp)
{
    Cell a(1, 2);
    Cell b(1, 3);
    Cell c(2, 2);

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(b < c);
    EXPECT_FALSE(c < a);

    EXPECT_FALSE(a < a);
}
