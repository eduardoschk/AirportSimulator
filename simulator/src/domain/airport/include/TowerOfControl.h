#pragma once

#ifndef INCLUDED_TOWER_OF_CONTROL_H
#define INCLUDED_TOWER_OF_CONTROL_H

#include <deque>
#include "Request.h"

class Log;
class Airport;
class Airplane;
class MyTimer;

class TowerOfControl
{
private:
   Log* log;
   Airport* airport;
   int limitAirplanes;
   int airplanesInLand;
   std::deque<Request*> requests;

   static TowerOfControl* instance;

   bool verifyRequest(Request& request);
   bool resolveLandingRequest(LandingRequest& landingRequest);
   bool resolveTakeOffRequest(TakeOffRequest& landingRequest);
   void requestResolved(Request& request);

   void verifyCriticalSituationCapacity();
   void verifyCriticalSituationWaiting();
   void verifyCriticalSituationTakeOffPending();
   
   TowerOfControl();
public:
   virtual ~TowerOfControl();

   void verifyAllRequests();

   long airplaneRequestLanding(Airplane* airplane);
   long airplaneRequestTakeOff(Airplane* airplane);

   void changedAirport(Airplane* airplane);

   int getNumberAirplanesOnGround();
   void setLimitAirplanes(int limit);

   std::deque<Request*> getRequests();

   static TowerOfControl* getInstance();
};

#endif // INCLUDED_TOWER_OF_CONTROL_H