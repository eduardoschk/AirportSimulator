#include "Direction.h"

bool Direction::areTransversesDirections(Direction::DIRECTIONS directionOne, Direction::DIRECTIONS directionTwo) {
   switch (directionOne) {
   case SOUTH:  case NORTH:
      return directionTwo != Direction::NORTH && directionTwo != Direction::SOUTH;
   case WEST: case EAST:
      return directionTwo != Direction::WEST && directionTwo != Direction::EAST;
   case NORTHEAST: case SOUTHWEST:
      return directionTwo != Direction::NORTHEAST && directionTwo != Direction::SOUTHWEST;
   case NORTHWEST: case SOUTHEAST:
      return directionTwo != Direction::NORTHWEST && directionTwo != Direction::SOUTHEAST;
   }
   return false;
}

std::string Direction::toString(DIRECTIONS direction) {
   switch (direction) {
   case SOUTH:       return "Sul";
   case NORTH:       return "Norte";   
   case WEST:        return "Oeste";
   case EAST:        return "Leste";
   case NORTHEAST:   return "Nordeste";
   case SOUTHWEST:   return "Sudoeste";
   case NORTHWEST:   return "Noroeste";
   case SOUTHEAST:   return "Sudeste";
   }
}