#pragma once
#ifndef DIRECTION_H
#define DIRECTION_H

namespace Direction {
   enum DIRECTIONS {SOUTH, NORTH, EAST, WEST, SOUTHWEST, SOUTHEAST, NORTHWEST, NORTHEAST};

   bool areTransversesDirections(DIRECTIONS directionOne, DIRECTIONS directionTwo);
}

#endif