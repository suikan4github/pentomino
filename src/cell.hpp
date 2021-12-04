#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief A point in the cartesian coordination.
 * 
 */
struct Cell
{
    int x_;
    int y_;

    /**
     * @brief Construct a new  object
     * 
     * @param x X coordination
     * @param y Y coordination
     */
    Cell(int x, int y) : x_(x), y_(y){};

    /**
     * @brief 
     * 
     * @param rhs 
     * @return true 
     * @return false 
     */
    bool operator==(const Cell &rhs) const
    {
        return (x_ == rhs.x_ &&
                y_ == rhs.y_);
    }

    bool operator!=(const Cell &rhs) const
    {
        return !(*this == rhs);
    }

    /**
     * @brief comparing two point a < b
     * 
     * @param rhs 
     * @return true a < b
     * @return false  a >= b
     * @details
     * Give the unique order to the 2D points. 
     */
    bool operator<(const Cell &rhs) const
    {
        bool lessthan = false;
        if (x_ < rhs.x_)
            lessthan = true;
        else if (x_ == rhs.x_)
            lessthan = y_ < rhs.y_;

        return lessthan;
    }
};