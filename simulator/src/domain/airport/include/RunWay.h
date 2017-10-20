#pragma once

#ifndef INCLUDED_RUNWAY_H
#define INCLUDED_RUNWAY_H

#include "Observer.h"
#include "Direction.h"

class Log;
class MyTimer;

class RunWay :
   public Observer
{
private:
   const Direction::DIRECTIONS directionRunWay;

   bool runWayFree;
   long timeToFreeRunWay;

   Log* log;

   void calculateTimeToFreeRunWay();

public:
   ~RunWay();
   RunWay(const Direction::DIRECTIONS _directionRunWay);

   bool isAvailable();
   void runwaySetToUse();

   Direction::DIRECTIONS getDirectionRunWay();
   
   void updateTime(long time);
};

#endif //INCLUDED_RUNWAY_H