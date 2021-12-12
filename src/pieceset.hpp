#pragma once

#include "piece.hpp"

/**
 * @brief Hold multiple Puzzle pieces
 * @details
 * The element of this vector is TransformedPieces class.
 * The TransformedPieces class object represetnts a set of transformed, normalized piece of a shape.
 *
 */
typedef std::vector<TransformedPieces> PieceSet;

/**
 * @brief Create a PieceSet correction of the unique Pentomino patterns.
 *
 * @param piece_set A collection of Transformed class. At first, it is empty vector. At the end, it will have 12 patterns.
 * @param cell_list A lst of cells under construction of 5 cell pieces. At the certain moment, its size is NOT 5.
 * @param cell Candidate of the new cell to the cell_list.
 * @details
 * Find out all 12 patterns of Pentomino pieces.
 *
 * User must call this function with piece_set as empty vector. The cell_list must contains only one Cell. This cell
 * becomes the origin of the piece. The initial coordination of that origin cell can be any.
 *
 * This function search the new piece pattern by recursive algorithm. For each time new pattern is found,
 * that is registered to the piece_set variable as correction of transformed style.
 */
void SearchAndAddPieces(PieceSet &piece_set, CellVector &cell_list, Cell cell);