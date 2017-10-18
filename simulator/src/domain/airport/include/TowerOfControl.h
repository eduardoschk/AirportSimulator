#pragma once

#ifndef TOWER_OF_CONTROL_H
#define TOWER_OF_CONTROL_H

#include <deque>
#include "Request.h"

class Log;
class Airport;
class Airplane;
class MyTimer;

class TowerOfControl
{
private:
   std::deque<Request*> requests;

   Airport* airport;

   int airplanesInLand;
   int limitAirplanes;

   static TowerOfControl* instance;

   Log* log;

   bool verifyRequest(Request& request);
   bool resolveLandingRequest(LandingRequest& landingRequest);
   bool resolveTakeOffRequest(TakeOffRequest& landingRequest);
   void requestResolved(Request& request);
   
   TowerOfControl();

public:
   virtual ~TowerOfControl();

   int getNumberAirplanesOnGround();
   void setLimitAirplanes(int limit);

   long airplaneRequestLanding(Airplane* airplane);
   long airplaneRequestTakeOff(Airplane* airplane);
   void changedAirport(Airplane* airplane);
   std::deque<Request*> getRequests();

   void verifyRequests();

   static TowerOfControl* getInstance();
};

#endif //TOWER_OF_CONTROL_H