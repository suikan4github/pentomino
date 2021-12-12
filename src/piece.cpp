#include "piece.hpp"

#include <assert.h>

Piece::Piece(CellVector &p)
{
    points_ = p;
    assert(p.size() == 5);
    Normalize();
}

bool Piece::operator==(const Piece &rhs) const
{
    bool eq = true;

    if (
        points_.size() == rhs.points_.size())
    {
        for (unsigned int i = 0; i < this->points_.size(); i++)
            if ((points_[i] != rhs.points_[i]))
            {
                eq = false;
                break;
            }
    }

    return eq;
}

// Sort the points then Shift first point to (0,0)
void Piece::Normalize()
{
    // Sort ascending order
    std::sort(points_.begin(), points_.end());

    // get offset
    auto x_offset = points_[0].x_;
    auto y_offset = points_[0].y_;

    // adjust offset to 0.
    for (auto &p : points_)
    {
        p.x_ -= x_offset;
        p.y_ -= y_offset;
    }
}

Piece Piece::MirrorByX()
{
    CellVector cv;

    // create an mirror copy on X axis
    for (auto const &cell : points_)
    {
        Cell new_cell(-cell.x_, cell.y_); // make a copy of element

        cv.push_back(new_cell); // append to vector
    }

    Piece new_piece(cv); // automatically normalized

    return new_piece;
}

Piece Piece::MirrorByY()
{
    CellVector cv;

    // create an mirror copy on Y axis
    for (auto const &cell : points_)
    {
        Cell new_cell(cell.x_, -cell.y_); // make a copy of element

        cv.push_back(new_cell); // append to vector
    }

    Piece new_piece(cv); // automatically normalized

    return new_piece;
}

Piece Piece::RotateBy90()
{
    CellVector cv;

    // create an CCW rotated copy
    for (auto const &cell : points_)
    {
        Cell new_cell(-cell.y_, cell.x_); // make a copy of element

        cv.push_back(new_cell); // append to vector
    }

    Piece new_piece(cv); // automatically normalized

    return new_piece;
}

TransformedPieces Piece::GenerateTransformedPieceVector()
{
    // create an empty vector of pieces.
    // This vector becomes a collection of the transformed pieces
    std::vector<Piece> piece_vector;

    // Add myself as first element
    piece_vector.push_back(*this);

    // first rotated transformation
    auto rv = RotateBy90();
    auto result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // second rotated transformation
    rv = rv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // third rotated transformation
    rv = rv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // ****************************
    // Mirrored transformation by X
    auto mv = MirrorByX();
    result = std::find(piece_vector.begin(), piece_vector.end(), mv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(mv);

    // first rotated transformation
    rv = mv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // second rotated transformation
    rv = rv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // third rotated transformation
    rv = rv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // ****************************
    // Mirrored transformation by Y
    mv = MirrorByY();
    result = std::find(piece_vector.begin(), piece_vector.end(), mv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(mv);

    // first rotated transformation
    rv = mv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // second rotated transformation
    rv = rv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    // third rotated transformation
    rv = rv.RotateBy90();
    result = std::find(piece_vector.begin(), piece_vector.end(), rv);
    if (result == piece_vector.end()) // if not registered yet
        piece_vector.push_back(rv);

    return piece_vector;
}

void Piece::Draw(unsigned char map[][9])
{
    // Make map blank.
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            map[i][j] = ' ';

    for (auto cell : points_)
        map[cell.x_ + 4][cell.y_ + 4] = '*';
}

// Where xpos and ypos are position in the map.
// We will try to place "this" piece to the coordination ( xpos, ypos )
// and check whether all cell of this piece is in the map or not
bool Piece::IsOutOfBound(int xpos, int ypos)
{

    // for all 5 cell of this piece
    for (const auto &c : this->points_)
    {
        if ((c.x_ + xpos >= xsize) || (0 > c.x_ + xpos)) // is OB on X axis?
            return true;
        if ((c.y_ + ypos >= ysize) || (0 > c.y_ + ypos)) // Is OB on Y axis?
            return true;
    }

    return false; // not OB.
}

// First, check if piece is out of bounds.
// If not, check there is overwrap with existing cell in the given map.
bool Piece::IsPossibleToPlace(Map map, int xpos, int ypos)
{
    if (IsOutOfBound(xpos, ypos)) // Is OB?
        return false;             // Not possible to place

    // for all 5 cell of this piece
    for (const auto &c : this->points_)
    {

        if (map[c.x_ + xpos][c.y_ + ypos] != unused)
            return false;
    }
    return true; // At here, it is possible to place
}
