#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

#include "piece.hpp"
#include "pieceset.hpp"

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
    Cell origin(0, 0);
    CellVector cv;
    PieceSet ps;

    SearchAndAddPieces(ps, cv, origin);

    unsigned int index = 1;

    for (int index = 0; index < ps.size(); index++)
    {
        std::cout << "Piece " << index << " has " << ps[index].size() << " pieces." << std::endl;
        //       for (int i = 0; i < ps[index].size(); i++)
        {
            int i = 0;
            std::cout << "Piece[" << index << "] form " << i << "/" << ps[index].size() << std::endl;
            PrintPiece(ps[index][i]);
        }
    }
}
