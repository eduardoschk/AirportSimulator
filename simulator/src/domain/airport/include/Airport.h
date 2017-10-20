#pragma once

#ifndef INCLUDED_AIRPORT_H
#define INCLUDED_AIRPORT_H

class RunWay;
class Airplane;
class WindMonitoring;

class Airport 
{
private: 
   RunWay* runWays[3];
   WindMonitoring* windMonitoring;

   static Airport* instance;

   Airport();

   RunWay* getRunWayAvailable();
   bool runWaysIsAvaible(RunWay* runWay);


public:
   ~Airport();
  
   bool airportIsAcessible();
   bool requestUseAirport(Airplane* _airplane);

   static Airport* getInstance();
};

#endif // INCLUDED_AIRPORT_H