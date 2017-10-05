#pragma once

#ifndef WIND_MONITORING_H
#define WIND_MONITORING_H

#include "Wind.h"
#include "Observer.h"

class WindFactory;
class MyTimer;

class WindMonitoring :
   public Observer
{
private: 
   long timeChangeOcurred;
   long timeNextChange;

   WindFactory* windFactory;
   Wind* actualWind;

   MyTimer* timer;

   static WindMonitoring* instance;

   void calculateNextTimeWindChange();

public:
   WindMonitoring();
   ~WindMonitoring() {}

   void directionWindChange(double degree);
   Wind* getActualWind();

   long getTimeChageOcurred();

   static WindMonitoring* getInstance();
   static void resetInstance();

   void updateTime(long time);
};

#endif