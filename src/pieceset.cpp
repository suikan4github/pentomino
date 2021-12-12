#include "pieceset.hpp"
#include <assert.h>

void SearchAndAddPieces(PieceSet &piece_set, CellVector &cell_list, Cell cell)
{
    bool need_to_add = false;

    if (cell_list.size() == 0) // is cell list empty?
        need_to_add = true;
    else if (std::find(cell_list.begin(), cell_list.end(), cell) != cell_list.end())                       // is cell already exist?
        ;                                                                                                  // no need to add
    else if (std::find(cell_list.begin(), cell_list.end(), Cell(cell.x_ + 1, cell.y_)) != cell_list.end()) // is cell exist at right next?
        need_to_add = true;
    else if (std::find(cell_list.begin(), cell_list.end(), Cell(cell.x_ - 1, cell.y_)) != cell_list.end()) // is cell exist at left next?
        need_to_add = true;
    else if (std::find(cell_list.begin(), cell_list.end(), Cell(cell.x_, cell.y_ + 1)) != cell_list.end()) // is cell exist on here?
        need_to_add = true;
    else if (std::find(cell_list.begin(), cell_list.end(), Cell(cell.x_, cell.y_ - 1)) != cell_list.end()) // is cell exist below here?
        need_to_add = true;

    if (need_to_add) // cell_list is empty or no duplication and next of existing cell
    {
        // let's add this cell.
        cell_list.push_back(cell);

        // If cell_list size is 5, we need to check whether same shape exist or not.
        if (cell_list.size() == 5) // we have all 5 Cells. So, let's check
        {
            Piece piece(cell_list); // create a new piece as normalized form from cell_list

            if (piece_set.size() == 0)
            {                                                                // If this is first created piece
                piece_set.push_back(piece.GenerateTransformedPieceVector()); // create a correction of transformed this piece
            }
            else // If not the first one
            {
                bool exists = false; // flag of "find!"
                // for all registered TransformedPices, check whether matched or not.
                for (auto const &tp : piece_set)
                {
                    // Check if new piece already exists in the transformed collection of registered piece
                    auto result = std::find(tp.begin(), tp.end(), piece);
                    if (result != tp.end()) // found?
                        exists = true;
                }

                if (!exists)
                {                                                                // if not found, this is new piece.
                    piece_set.push_back(piece.GenerateTransformedPieceVector()); // Add a new piece to the correction
                }
                assert(12 >= piece_set.size()); // Theoretical number of the unique Pentomino is 12.
            }

            // check wether the piece already exist
        }
        else // We need more Cell
        {
            for (int i = -4; i < 5; i++)
                for (int j = -4; j < 5; j++)
                    SearchAndAddPieces(piece_set, cell_list, Cell(i, j));
        }

        cell_list.pop_back(); // remove the given cell from the piece.
    }
    // If the Cell is already exist in the piece, do nothing.
}
