#pragma once

#ifndef WIND_MONITORING_H
#define WIND_MONITORING_H

#include "Wind.h"
#include <iostream>

class WindFactory;

class WindMonitoring
{
private: 
   Wind* actualWind;
   WindFactory* windFactory;
   static WindMonitoring* instance;

protected:
   WindMonitoring();

public:
   ~WindMonitoring() {}
   void directionWindChange(double degree);
   Wind* getActualWind();

   static WindMonitoring* getInstance();
   static void resetInstance();
};

#endif