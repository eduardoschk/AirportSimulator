#include <iostream>
#include "MyTimer.h"
#include "RunWay.h"
#include "Log.h"

RunWay::RunWay(const Direction::DIRECTIONS _directionRunWay) : directionRunWay(_directionRunWay), runWayFree(true), log(Log::getInstance()) 
{
   MyTimer::getTimer()->addObserver(this);
}

RunWay::~RunWay() 
{
   MyTimer::getTimer()->removeObserver(this);
}

///////////////////////////////////////////////////////////////////////////////

void RunWay::calculateTimeToFreeRunWay() 
{
   timeToFreeRunWay= MyTimer::getTimer()->getActualTime() + 3;
}

///////////////////////////////////////////////////////////////////////////////

bool RunWay::isAvailable() 
{  
   return runWayFree;
}

void RunWay::runwaySetToUse() 
{
   runWayFree= false;
   calculateTimeToFreeRunWay();
}

///////////////////////////////////////////////////////////////////////////////

Direction::DIRECTIONS RunWay::getDirectionRunWay()
{
   return directionRunWay;
}

///////////////////////////////////////////////////////////////////////////////

void RunWay::updateTime(const long time) 
{
   if (!runWayFree) 
   {
      if (time >= timeToFreeRunWay) 
      {
         runWayFree= true;
         log->registryEvent(EVENT_RUN_WAY_FREE, &(Direction::toString(directionRunWay)));
      }
   }
}