#pragma once

#ifndef WIND_CONTROLLER_H
#define WIND_CONTROLLER_H

#include "Observer.h"

class MyTimer;
class WindMonitoring;

class WindController :
   public Observer
{
private:
   long timeToChangeWind;

   MyTimer* timer;
   WindMonitoring* windMonitoring;

   void calculateTimeWindChange();
   void changeWind();

public:
   ~WindController();
   WindController();

   void updateTime(const long time);
};

#endif //WIND_CONTROLLER_H