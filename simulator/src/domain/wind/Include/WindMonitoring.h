#pragma once

#ifndef INCLUDED_WIND_MONITORING_H
#define INCLUDED_WIND_MONITORING_H

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

   Wind& getActualWind();

   static WindMonitoring* getInstance();
};

#endif // INCLUDED_WIND_MONITORING_H