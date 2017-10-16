#pragma once

#ifndef RUNWAY_H
#define RUNWAY_H

#include "Direction.h"
#include "Observer.h"

class MyTimer;

class RunWay :
   public Observer
{
private:
   const Direction::DIRECTIONS directionRunWay;

   bool runWayFree;
   long timeToFreeRunWay;

   void calculateTimeToFreeRunWay();

public:
   ~RunWay();
   RunWay(const Direction::DIRECTIONS _directionRunWay);

   bool isAvailable();
   Direction::DIRECTIONS getDirectionRunWay() { return directionRunWay; }
   void runwayPutToUse();

   void updateTime(long time);

};

#endif