#include "main.hpp"

/**
 * @brief Output formatter for Cell type
 *
 * @param os Output stream
 * @param p Cell variable
 * @return std::ostream&
 */
std::ostream &
operator<<(std::ostream &os, const Cell &p)
{
    os << '(' << p.x_ << ',' << p.y_ << ')';
    return os;
}

int main(int, char **)
{
    signed char map[vsize][hsize];

    Cell origin(0, 0);
    CellVector cv;
    PieceSet ps;

    // Generate 12 Pentomino pieces with its transformed variant.
    SearchAndAddPieces(ps, cv, origin);

    // Count the possible pattern.
    int count = ScanMap(map, 0, ps);
}
