#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

#include "piece.hpp"
#include "pieceset.hpp"

/**
 * @brief Vertical size of map.
 *
 */
const unsigned int vsize = 6;
/**
 * @brief HHorizontal size of map.
 *
 */
const unsigned int hsize = 10;

/**
 * @brief Initial value of map element.
 *
 */
const signed char unused = -1;

/**
 * @brief Construct a new Is Out Of Bound object
 *
 * @param map v*h map. must be initialized by @ref unused.
 * @param piece_index  0..11.
 * @param piece_set  Vector of the pieces. Each element is the correction of transformed pieces.
 * @return how much placement was successful.
 * @details
 * Try to place the piece specified by piece_index on the given map.  If it is able to place,
 * Mark the map by given piece_index. Placement is tried with all transformed piece.
 *
 * After marking, call itself with incremented piece_index.
 *
 * If the index is 11 and placement is successful, return 1. If fail, return 0.
 * If the piece_index is not 111, accumulate the returned value and return it.
 *
 * For each successful trial is done, the map is cleared by @ref unused.
 */
int ScanMap(signed char map[][hsize], int piece_index, PieceSet &piece_set);

/**
 * @brief Check wether the given piece is inside map or not.
 *
 * @param map vsize*hsize map.
 * @param x horizontal index. 0.. hsize-1.
 * @param y vertical index. 0.. vsize-1.
 * @param piece Piece try to place.
 * @return true Piece is not completely inside map
 * @return false Piece is completely inside map
 * @details
 * Check with the map boundary. If some cell of given piece is outside of vsize*hsize map, return true.
 */
bool IsOutOfBound(signed char map[][hsize], int x, int y, Piece const &piece);

/**
 * @brief CHeck whether piece is oke to place on map or not.
 *
 * @param map vsize*hsize map.
 * @param x horizontal index. 0.. hsize-1.
 * @param y vertical index. 0.. vsize-1.
 * @param piece Piece try to place.
 * @return true Piece is OK to place.
 * @return false Piece is not OK to place. Some duplication or OB.
 * @details
 * Call @IsOutOfBound() at first. If it returns false, check wether the cell is already used or not.
 * If not used, return true.
 */
bool IsPossibleToPlace(signed char map[][hsize], int x, int y, Piece const &piece);

/**
 * @brief Mark the map
 *
 * @param map vsize*hsize map.
 * @param x horizontal index. 0.. hsize-1.
 * @param y vertical index. 0.. vsize-1.
 * @param piece Piece try to place.
 * @param mark Place to map.
 * @details
 * Write mark to the point in map where cell is going to place.
 */
void PlacePiece(signed char map[][hsize], int x, int y, Piece const &piece, signed char mark);

/**
 * @brief Unmark the map.
 *
 * @param map vsize*hsize map.
 * @param x horizontal index. 0.. hsize-1.
 * @param y vertical index. 0.. vsize-1.
 * @param piece Piece try to place.
 * @details
 * Write @ref unused to the point in map where cell is going to place.
 */
void RemovePiece(signed char map[][hsize], int x, int y, Piece const &piece);