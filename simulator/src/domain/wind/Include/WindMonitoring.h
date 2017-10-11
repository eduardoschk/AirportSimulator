#pragma once

#ifndef WIND_MONITORING_H
#define WIND_MONITORING_H

#include "Wind.h"

class WindFactory;

class WindMonitoring
{
private: 

   WindFactory* windFactory;
   Wind* actualWind;

   static WindMonitoring* instance;

   WindMonitoring();

public:
   ~WindMonitoring();

   void directionWindChange(double degree);
   Wind* getActualWind();

   long getTimeChageOcurred();

   static WindMonitoring* getInstance();
};

#endif