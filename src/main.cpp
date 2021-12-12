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
    //    int count = ScanMap(map, 0, ps);
}
