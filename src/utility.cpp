#include "utility.hpp"
#include "cstring"

void InitializeMap(Map map)
{

    std::memset(map, unused, sizeof(Map));
}

std::ostream &
operator<<(std::ostream &os, const Cell &p)
{
    os << '(' << p.x_ << ',' << p.y_ << ')';
    return os;
}

void PrintPiece(Piece p)

{
    unsigned char map[9][9];

    p.Draw(map);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            std::cout << map[i][j];

        std::cout << std::endl;
    }
}
