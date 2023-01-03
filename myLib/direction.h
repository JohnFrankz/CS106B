/*
 * File: direction.h
 * -----------------
 * This interface exports an enumerated type called Direction whose elements 
 * are the four compass points: NORTH, EAST, SOUTH, and WEST.
 */

#ifndef _direction_h
#define _direction_h

#include <string>

/*
 * Type: Direction
 * ---------------
 * This enumerated typr is used to respresent the four compass directions.
 */

enum Direction {
    NORTH, EAST, SOUTH, WEST
};

/*
 * Function: leftFrom
 * Usage: Direction newdir = leftFrom(dir);
 * ----------------------------------------
 * Return the direction that is to left of the argument.
 * For example, leftFrom(NORTH) return WEST.
 */

Direction leftForm(Direction dir);

/*
 * Function: rightFrom
 * Usage: Direction newdir = rightFrom(dir);
 * ----------------------------------------
 * Return the direction that is to right of the argument.
 * For example, rightFrom(NORTH) return EAST.
 */

Direction rightForm(Direction dir);

/*
 * Function: directionToString 
 * Usage: string str = directionToString(dir);
 * -------------------------------------------
 * Returns théname of the direction as a string.
 */

std::string directionToString(Direction dir);

#endif;
