#include <iostream>
#include "MyTimer.h"
#include "RunWay.h"
#include "Log.h";

RunWay::RunWay(const Direction::DIRECTIONS _directionRunWay) : directionRunWay(_directionRunWay), runWayFree(true), log(Log::getInstance()) {
   MyTimer::getTimer()->add(this);
}

RunWay::~RunWay() {
   MyTimer::getTimer()->remove(this);
}

void RunWay::calculateTimeToFreeRunWay() {
   timeToFreeRunWay= MyTimer::getTimer()->getActualTime() + 3;
}

void RunWay::runwayPutToUse() {
   runWayFree= false;
   calculateTimeToFreeRunWay();
}

bool RunWay::isAvailable() {  
   return runWayFree;
}

void RunWay::updateTime(long time) {
   if (!runWayFree) {
      if (time >= timeToFreeRunWay) {
         runWayFree= true;
         log->registryEvent(EVENTRUNWAYFREE, &(Direction::toString(directionRunWay)));
      }
   }
}