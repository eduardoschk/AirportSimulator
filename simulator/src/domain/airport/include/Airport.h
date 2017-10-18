#pragma once

#ifndef AIRPORT_H
#define AIRPORT_H

#include <exception>

class Airplane;
class WindMonitoring;
class RunWay;

class Airport 
{
private: 
   WindMonitoring* windMonitoring;
   RunWay* runWays[3];

   RunWay* getRunWayAvailable();
   bool runWaysIsAvaible(RunWay* runWay);

   static Airport* instance;

   Airport();

public:
   ~Airport();

   static Airport* getInstance();

   class NoRunWaysAvaible : public std::exception { virtual const char* what() const { return "Sem pista de pouso liberada"; } };
  
   bool airportIsAcessible();
   bool requestUseAirport(Airplane* _airplane);
};

#endif //AIRPORT_H