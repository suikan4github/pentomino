#include "pentomino.hpp"
#include "cell.hpp"
#include "piece.hpp"

/**
 * @brief Initialize given map by "unused"
 *
 * @param map
 */
void InitializeMap(Map map);

/**
 * @brief Output formatter for Cell type
 *
 * @param os Output stream
 * @param p Cell variable
 * @return std::ostream&
 */
std::ostream &
operator<<(std::ostream &os, const Cell &p);

void PrintPiece(Piece p);
