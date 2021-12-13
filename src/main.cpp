#include "main.hpp"
#include "utility.hpp"

int main(int, char **)
{
    Map map;

    Cell origin(0, 0);
    CellVector cv;
    PieceSet ps;

    InitializeMap(map);

    // Generate 12 Pentomino pieces with its transformed variant.
    SearchAndAddPieces(ps, cv, origin);

    // Count the possible pattern.
    int count = ScanMap(map, 0, ps);
    std::cout << "Pentomino : " << count << std::endl;
}

int ScanMap(Map map, int piece_index, PieceSet &piece_set)
{
    assert(piece_index < 12);
    int sum = 0;

    // Scan all cells.
    for (int x = 0; x < xsize; x++)
        for (int y = 0; y < ysize; y++)
        {
            if (map[x][y] == unused)                   // Try only when the cell is not used.
                for (auto &p : piece_set[piece_index]) // Try all transformed variation
                {
                    if (p.IsPossibleToPlace(map, x, y)) // Can we place a piece?
                    {
                        p.PlacePiece(map, x, y, piece_index);
                        if (piece_index == 11)                               // Is last Pentomino patterm?
                            sum += 1;                                        // gotcha! all piece fits.
                        else                                                 // Not last pattern
                            sum += ScanMap(map, piece_index + 1, piece_set); // challenge next pattern
                        p.RemovePiece(map, x, y);                            // Before going next cell, clean up.
                    }
                }
        }
    return sum;
}