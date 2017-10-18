#pragma once

#ifndef WIND_MONITORING_H
#define WIND_MONITORING_H

#include "Wind.h"

class WindFactory;
class Log;

class WindMonitoring
{
private: 

   WindFactory* windFactory;
   Wind* actualWind;

   static WindMonitoring* instance;

   Log* log;

   WindMonitoring();

public:
   ~WindMonitoring();

   void directionWindChange(double degree);
   Wind* getActualWind();

   long getTimeChageOcurred();

   static WindMonitoring* getInstance();
};

#endif // WIND_MONITORING_H