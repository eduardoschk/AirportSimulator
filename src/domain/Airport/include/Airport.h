#pragma once

#ifndef AIRPORT_H
#define AIRPORT_H

#include <exception>
#include "Airplane.h"
#include "WindMonitoring.h"
#include "Direction.h"
#include "RunWay.h"
#include <queue>
#include "Request.h"

class Airplane;

class Airport 
{
private: 
   WindMonitoring* windMonitoring;

   std::queue<Request*> requests;
   RunWay* runWays[3];

   bool existsRunWayAvaible();
   RunWay* getRunWayAvaible();
   bool runWaysIsAvaible(RunWay* runWay);
   

protected:
   Airport();
   ~Airport() {}

public:
   static Airport* getInstance();
   static void resetInstance();

   /*class ClosedAirport : public std::exception { virtual const char* what() const { return "Aeroporto fechado"; } };
   class NoRunWaysAvaible : public std::exception { virtual const char* what() const { return "Sem pista de pouso liberada"; } };*/
   void requestUseAirport(Airplane* _airplane);
   void verifyRequests();

};

#endif