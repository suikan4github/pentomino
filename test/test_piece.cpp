// Test cases for the Piece class

#include "gtest/gtest.h"
#include "piece.hpp"
#include "utility.hpp"
#include <stdexcept>

TEST(PieceDeathTest, SizeSmall)
{
    Cell a(2, 2);
    Cell b(1, 1);
    Cell c(3, 3);
    Cell d(5, 5);
    Cell e(4, 4);

    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

#ifndef NDEBUG
    // We test only when assert() works.
    ASSERT_DEATH(Piece p(v), "p.*5");
#endif
}

TEST(PieceDeathTest, SizeLarge)
{
    Cell a(2, 2);
    Cell b(1, 1);
    Cell c(3, 3);
    Cell d(5, 5);
    Cell e(4, 4);

    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);
    v.push_back(d);

#ifndef NDEBUG
    // We test only when assert() works.
    ASSERT_DEATH(Piece p(v), "p.*5");
#endif
}

// Check if normalize() works.
TEST(Piece, Normalize)
{
    Cell a(2, 2);
    Cell b(1, 1);
    Cell c(3, 3);
    Cell d(5, 5);
    Cell e(4, 4);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);

    EXPECT_TRUE((p.points_[0].x_ == 0) && (p.points_[0].y_ == 0));
    EXPECT_TRUE((p.points_[1].x_ == 1) && (p.points_[1].y_ == 1));
    EXPECT_TRUE((p.points_[2].x_ == 2) && (p.points_[2].y_ == 2));
    EXPECT_TRUE((p.points_[3].x_ == 3) && (p.points_[3].y_ == 3));
    EXPECT_TRUE((p.points_[4].x_ == 4) && (p.points_[4].y_ == 4));
}

// Check if "==" op works
TEST(Piece, EqOp)
{
    Cell a(2, 2);
    Cell b(1, 1);
    Cell c(3, 3);
    Cell d(5, 5);
    Cell e(4, 4);
    std::vector<Cell> v1;
    std::vector<Cell> v2;
    Cell f(2, 2);
    Cell g(1, 1);
    Cell h(3, 4);
    Cell i(5, 5);
    Cell j(4, 4);
    std::vector<Cell> v3;

    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);
    v1.push_back(d);
    v1.push_back(e);

    v2.push_back(a);
    v2.push_back(b);
    v2.push_back(c);
    v2.push_back(d);
    v2.push_back(e);

    v3.push_back(f);
    v3.push_back(g);
    v3.push_back(h);
    v3.push_back(i);
    v3.push_back(j);

    Piece p1(v1);
    Piece p2(v2);
    Piece p3(v3);

    EXPECT_TRUE(p1 == p2);
}

// Check if MirrorByX() works
TEST(Piece, MirrorByX)
{
    Cell b(1, 1);
    Cell a(2, 2);
    Cell c(3, 3);
    Cell e(4, 4);
    Cell d(5, 3);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);
    Piece mp = p.MirrorByX();

    EXPECT_EQ(mp.points_[0].x_, 0);
    EXPECT_EQ(mp.points_[0].y_, 0);
    EXPECT_EQ(mp.points_[1].x_, 1);
    EXPECT_EQ(mp.points_[1].y_, 1);
    EXPECT_EQ(mp.points_[2].x_, 2);
    EXPECT_EQ(mp.points_[2].y_, 0);
    EXPECT_EQ(mp.points_[3].x_, 3);
    EXPECT_EQ(mp.points_[3].y_, -1);
    EXPECT_EQ(mp.points_[4].x_, 4);
    EXPECT_EQ(mp.points_[4].y_, -2);
}

// Check if MirrorByY() works
TEST(Piece, MirrorByY)
{
    Cell b(1, 1);
    Cell a(2, 2);
    Cell c(3, 3);
    Cell e(4, 4);
    Cell d(5, 3);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);
    Piece mp = p.MirrorByY();

    EXPECT_EQ(mp.points_[0].x_, 0);
    EXPECT_EQ(mp.points_[0].y_, 0);
    EXPECT_EQ(mp.points_[1].x_, 1);
    EXPECT_EQ(mp.points_[1].y_, -1);
    EXPECT_EQ(mp.points_[2].x_, 2);
    EXPECT_EQ(mp.points_[2].y_, -2);
    EXPECT_EQ(mp.points_[3].x_, 3);
    EXPECT_EQ(mp.points_[3].y_, -3);
    EXPECT_EQ(mp.points_[4].x_, 4);
    EXPECT_EQ(mp.points_[4].y_, -2);
}

// Check if RotateBy90() works
TEST(Piece, RotateBy90)
{
    Cell b(1, 1);
    Cell a(2, 2);
    Cell c(3, 3);
    Cell e(4, 4);
    Cell d(5, 3);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);
    Piece rp = p.RotateBy90();

    EXPECT_EQ(rp.points_[0].x_, 0);
    EXPECT_EQ(rp.points_[0].y_, 0);
    EXPECT_EQ(rp.points_[1].x_, 1);
    EXPECT_EQ(rp.points_[1].y_, -1);
    EXPECT_EQ(rp.points_[2].x_, 1);
    EXPECT_EQ(rp.points_[2].y_, 1);
    EXPECT_EQ(rp.points_[3].x_, 2);
    EXPECT_EQ(rp.points_[3].y_, -2);
    EXPECT_EQ(rp.points_[4].x_, 3);
    EXPECT_EQ(rp.points_[4].y_, -3);
}

// Check if GenerateTransformedPieceVector() works.
// Test by "/" shape.
// o
//  o
//   o
//    o
//     o

TEST(Piece, GenerateTransformedPieceVector1)
{
    Cell b(1, 1);
    Cell a(2, 2);
    Cell c(3, 3);
    Cell e(4, 4);
    Cell d(5, 5);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);
    auto tp = p.GenerateTransformedPieceVector();

    EXPECT_EQ(tp.size(), 2);
}

// Check if GenerateTransformedPieceVector() works.
// Test by "+" shape.
//  o
// ooo
//  o
TEST(Piece, GenerateTransformedPieceVector2)
{
    Cell b(1, 1);
    Cell a(2, 1);
    Cell c(3, 1);
    Cell e(2, 2);
    Cell d(2, 0);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);
    auto tp = p.GenerateTransformedPieceVector();

    EXPECT_EQ(tp.size(), 1);
}

// Check if GenerateTransformedPieceVector() works.
// Test by "b" shape.
// oo
// ooo
TEST(Piece, GenerateTransformedPieceVector3)
{
    Cell b(1, 1);
    Cell a(2, 1);
    Cell c(1, 2);
    Cell e(2, 2);
    Cell d(3, 2);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);
    auto tp = p.GenerateTransformedPieceVector();

    EXPECT_EQ(tp.size(), 8);
}

// Check IsOutOfBound() works
// Test by "b" shape.
// oo
// ooo
TEST(Piece, OutOfBound)
{
    Cell b(1, 1);
    Cell a(2, 1);
    Cell c(1, 2);
    Cell e(2, 2);
    Cell d(3, 2);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);

    EXPECT_TRUE(p.IsOutOfBound(-1, 0));    // explicit test
    EXPECT_TRUE(p.IsOutOfBound(0, -1));    // explicit test
    EXPECT_TRUE(p.IsOutOfBound(xsize, 0)); // explicit test
    EXPECT_TRUE(p.IsOutOfBound(0, ysize)); // explicit test

    // oo
    // ooo
    EXPECT_FALSE(p.IsOutOfBound(0, 0));         // Must OK
    EXPECT_FALSE(p.IsOutOfBound(xsize - 3, 0)); // Must OK
    EXPECT_TRUE(p.IsOutOfBound(xsize - 2, 0));  // Must NG
    EXPECT_FALSE(p.IsOutOfBound(0, ysize - 2)); // Must OK
    EXPECT_TRUE(p.IsOutOfBound(0, ysize - 1));  // Must NG
}

// Check IsPossibleToPlace() works
// Test by "b" shape.
// oo
// ooo
TEST(Piece, IsPossibleToPlace)
{
    Cell b(1, 1);
    Cell a(2, 1);
    Cell c(1, 2);
    Cell e(2, 2);
    Cell d(3, 2);
    std::vector<Cell> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);

    Piece p(v);

    Map map;
    InitializeMap(map);

    // oo
    // ooo
    EXPECT_TRUE(p.IsPossibleToPlace(map, 0, 0));          // Must OK
    EXPECT_TRUE(p.IsPossibleToPlace(map, xsize - 3, 0));  // Must OK
    EXPECT_FALSE(p.IsPossibleToPlace(map, xsize - 2, 0)); // Must NG
    EXPECT_TRUE(p.IsPossibleToPlace(map, 0, ysize - 2));  // Must OK
    EXPECT_FALSE(p.IsPossibleToPlace(map, 0, ysize - 1)); // Must NG

    map[5][1] = 1; // use a cell

    EXPECT_FALSE(p.IsPossibleToPlace(map, 5, 1)); // Must NG
    EXPECT_TRUE(p.IsPossibleToPlace(map, 6, 1));  // Must OK
    EXPECT_TRUE(p.IsPossibleToPlace(map, 5, 2));  // Must OK
    EXPECT_FALSE(p.IsPossibleToPlace(map, 4, 1)); // Must NG
    EXPECT_FALSE(p.IsPossibleToPlace(map, 5, 0)); // Must NG
}