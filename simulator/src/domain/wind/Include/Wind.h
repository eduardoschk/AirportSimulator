#pragma once

#ifndef WIND_H
#define WIND_H

#include "Direction.h"

class Wind {
public:
   Wind() {}
   ~Wind() {}

   virtual Direction::DIRECTIONS getDirectionWind() = 0;
};

class SouthWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::SOUTH;
   }
};

class NorthWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::NORTH;
   }
};

class EastWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::EAST;
   }
};

class WestWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::WEST;
   }
};

class SouthwestWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::SOUTHWEST;
   }
};

class SoutheastWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::SOUTHEAST;
   }
};

class NorthwestWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::NORTHWEST;
   }
};

class NortheastWind : public Wind {
   Direction::DIRECTIONS getDirectionWind() {
      return Direction::NORTHEAST;
   }
};

#endif // WIND_H