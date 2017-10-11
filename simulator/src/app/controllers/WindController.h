#pragma once

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