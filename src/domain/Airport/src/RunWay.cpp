#include <iostream>
#include "MyTimer.h"
#include "RunWay.h"

RunWay::RunWay(Direction::DIRECTIONS _directionRunWay) : directionRunWay(_directionRunWay), invalidLandingRunWayStartTime(-1), timer(MyTimer::getTimer()) {}

void RunWay::runwayInUse() {
   invalidLandingRunWayStartTime= timer->getActualTime();
}

bool RunWay::isAvaible() {
   if (invalidLandingRunWayStartTime < 0)
      return true;
   else if (timer->differenceBetweenActualTimeInSeconds(invalidLandingRunWayStartTime) >= 3) {
      invalidLandingRunWayStartTime= -1;
      return true;
   } else 
      return false;
}