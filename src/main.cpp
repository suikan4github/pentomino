#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

#include "piece.hpp"

/**
 * @brief Hold multiple Puzzle pieces
 * 
 */
typedef std::vector<TransformedPieces> PieceSet;

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

void AddPieces(PieceSet &piece_set, CellVector &cell_list, Cell cell)
{
    auto result = std::find(cell_list.begin(), cell_list.end(), cell);

    if (result == cell_list.end()) // Not found
    {
        cell_list.push_back(cell);

        if (cell_list.size() == 5) // we have all 5 Cell
        {
            Piece piece(cell_list); // create a new piece as normalized form

            if (piece_set.size() == 0)                                       // If this is first created piece
                piece_set.push_back(piece.GenerateTransformedPieceVector()); // create a correction of transformed this piece
            else                                                             // If not the first one
            {
                bool exists = false;
                // for all registered pieces?
                for (auto const &pv : piece_set)
                {
                    // Check if new piece already exists in the transformed collection of a piece
                    auto result = std::find(pv.begin(), pv.end(), piece);
                    if (result != pv.end())
                        exists = true;
                }

                if (!exists)                                                     // if not found, this is new piece.
                    piece_set.push_back(piece.GenerateTransformedPieceVector()); // Add a new piece to the correction

                assert(12 >= piece_set.size()); // Theoretical number of the unique Pentomino is 12.
            }

            // check wether the piece already exist
        }
        else // We need more Cell
        {
            AddPieces(piece_set, cell_list, Cell(cell.x_ + 1, cell.y_));
            AddPieces(piece_set, cell_list, Cell(cell.x_, cell.y_ + 1));
            AddPieces(piece_set, cell_list, Cell(cell.x_ - 1, cell.y_));
            AddPieces(piece_set, cell_list, Cell(cell.x_, cell.y_ - 1));
        }

        cell_list.pop_back(); // remove the given point from the piece.
    }
    // If the Cell is already exist in the piece, do nothing.
}

int main(int, char **)
{
    CellVector p;

    p.push_back({1, 2});
    p.push_back({3, 4});

    auto result = std::find(p.begin(), p.end(), Cell(3, 4));

    if (p.end() == result)
        std::cout << "No match" << std::endl;
    std::cout << std::distance(p.begin(), result) << std::endl;
}
