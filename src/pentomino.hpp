#pragma once
#include <stdint.h>

/**
 * @brief Vertical size of map.
 *
 */
const unsigned int ysize = 6;
/**
 * @brief HHorizontal size of map.
 *
 */
const unsigned int xsize = 10;

/**
 * @brief Initial value of map element.
 *
 */
const signed char unused = -1;

typedef int8_t Map[xsize][ysize];