#include <iostream>
#include <vector>
#include <algorithm>

#include "cell.hpp"

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
