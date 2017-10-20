#pragma once

#ifndef INCLUDED_WIND_CONTROLLER_H
#define INCLUDED_WIND_CONTROLLER_H

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

   void changeWind();
   void calculateTimeWindChange();

public:
   ~WindController();
   WindController();

   void updateTime(const long time);
};

#endif // INCLUDED_WIND_CONTROLLER_H