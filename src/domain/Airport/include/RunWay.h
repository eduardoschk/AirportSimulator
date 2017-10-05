#pragma once

#ifndef RUNWAY_H
#define RUNWAY_H

#include "Direction.h"

class MyTimer;

class RunWay
{
private:
   Direction::DIRECTIONS directionRunWay;
   long invalidLandingRunWayStartTime;

   MyTimer* timer;

public:
   ~RunWay() {}
   RunWay(Direction::DIRECTIONS _directionRunWay);

   bool isAvaible();
   Direction::DIRECTIONS getDirectionRunWay() { return directionRunWay; }
   void runwayInUse();

};

#endif