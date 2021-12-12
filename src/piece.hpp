#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "cell.hpp"
#include "pentomino.hpp"

#ifndef FRIEND_TEST
#define FRIEND_TEST(x, y)
#endif

/**
 * @brief Piece of puzzle.
 * @details
 * Contains 5 coordination
 *
 */
typedef std::vector<Cell> CellVector;

/**
 * @brief Actual 5 cells piece.
 *
 */
class Piece;

/**
 * @brief Collection of all transformantion of a piece
 * @details
 * A collection of delivered transformation from one piece.
 * The transformation means:
 * @li Mirrored
 * @li Rotated
 * Contains the original piece. No duplication in a collection.
 */
typedef std::vector<Piece> TransformedPieces;

class Piece
{
public:
    Piece(CellVector &cell_list);
    bool operator==(const Piece &rhs) const;
    /**
     * @brief Draw on the given 9x9 map
     *
     * @param map 9x9 map.
     */
    void Draw(unsigned char map[][9]);

    /**
     * @brief Create a vector of the Pieces.
     *
     * @return std::vector<Piece>
     * @details
     * Each piece represents :
     * @li itself
     * @li rotation
     * @li mirror
     * No duplication
     */
    TransformedPieces GenerateTransformedPieceVector();

    /**
     * @brief Check wether the given piece is inside map or not.
     *
     * @param x horizontal index. 0.. hsize-1.
     * @param y vertical index. 0.. vsize-1.
     * @return true Piece is not completely inside map
     * @return false Piece is completely inside map
     * @details
     * Check with the map boundary. If some cell of given piece is outside of vsize*hsize Map map, return true.
     */
    bool IsOutOfBound(int xpos, int ypos);

    /**
     * @brief CHeck whether piece is oke to place on map or not.
     *
     * @param map vsize*hsize map.
     * @param x horizontal index. 0.. hsize-1.
     * @param y vertical index. 0.. vsize-1.
     * @return true Piece is OK to place.
     * @return false Piece is not OK to place. Some duplication or OB.
     * @details
     * Call @IsOutOfBound() at first. If it returns false, check wether the cell is already used or not.
     * If not used, return true.
     */
    bool IsPossibleToPlace(Map map, int xpos, int ypos);

    /**
     * @brief Mark the map
     *
     * @param map vsize*hsize map.
     * @param x horizontal index. 0.. hsize-1.
     * @param y vertical index. 0.. vsize-1.
     * @param mark Place to map.
     * @details
     * Write mark to the point in map where cell is going to place.
     */
    void PlacePiece(Map map, int xpos, int ypos, signed char mark);

    /**
     * @brief Unmark the map.
     *
     * @param map vsize*hsize map.
     * @param x horizontal index. 0.. hsize-1.
     * @param y vertical index. 0.. vsize-1.
     * @details
     * Write @ref unused to the point in map where cell is going to place.
     */
    void RemovePiece(Map map, int xpos, int ypos);

private:
    FRIEND_TEST(Piece, Normalize);
    FRIEND_TEST(Piece, EqOp);
    FRIEND_TEST(Piece, MirrorByX);
    FRIEND_TEST(Piece, MirrorByY);
    FRIEND_TEST(Piece, RotateBy90);
    CellVector points_;

    // Sort cells, then, move to the (0,0) origine ( 1st cell is set to origin )
    void Normalize();
    // Make copy as Mirror of this
    Piece MirrorByX();
    // Make copy as Mirror of this
    Piece MirrorByY();
    // Make 90 degree rotation of this
    Piece RotateBy90();
};
