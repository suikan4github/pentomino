// Test cases for the Piece class

#include "gtest/gtest.h"
#include "pieceset.hpp"
#include <stdexcept>

TEST(PieceSet, SearchAndAddPieces)
{
    Cell origin(1, 1);
    CellVector cv;
    PieceSet ps;

    SearchAndAddPieces(ps, cv, origin);

    EXPECT_EQ(ps.size(), 12);
}