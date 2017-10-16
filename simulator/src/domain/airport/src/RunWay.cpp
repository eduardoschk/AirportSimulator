#include <iostream>
#include "MyTimer.h"
#include "RunWay.h"

RunWay::RunWay(const Direction::DIRECTIONS _directionRunWay) : directionRunWay(_directionRunWay), runWayFree(true) {
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
         std::cout << "Pista Liberada! " << Direction::toString(getDirectionRunWay()) << "\n\n";
         runWayFree= true;
      }
   }
}