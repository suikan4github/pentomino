#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

#include "piece.hpp"
#include "pieceset.hpp"

#include "pentomino.hpp"

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
int ScanMap(signed char map[][xsize], int piece_index, PieceSet &piece_set);
