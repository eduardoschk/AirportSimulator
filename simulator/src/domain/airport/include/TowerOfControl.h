#pragma once

#include <deque>
#include "Observer.h"
#include "Request.h"

class Airport;
class Airplane;
class MyTimer;

class TowerOfControl :
   public Observer
{
private:
   std::deque<Request*> requests;

   Airport* airport;

   int airplanesInLand;
   int limitAirplanes;
   
   MyTimer* timer;

   static TowerOfControl* instance;

   void verifyRequests();
   bool verifyRequest(Request& request);
   bool resolveLandingRequest(LandingRequest& landingRequest);
   bool resolveTakeOffRequest(TakeOffRequest& landingRequest);
   void requestResolved(Request& request);
   
   TowerOfControl();

public:
   virtual ~TowerOfControl();

   void setLimitAirplanes(int limit);

   long airplaneRequestLanding(Airplane* airplane);
   long airplaneRequestTakeOff(Airplane* airplane);
   void changedAirport(Airplane* airplane);
   void updateTime(long time);

   static TowerOfControl* getInstance();
};

