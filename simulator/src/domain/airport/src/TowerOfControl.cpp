#include "TowerOfControl.h"
#include "Airplane.h"
#include "Request.h"
#include "Airport.h"
#include "MyTimer.h"
#include "MyRandom.h"

//teste
#include <iostream>

TowerOfControl::TowerOfControl() : airport(Airport::getInstance()), timer(MyTimer::getTimer()), airplanesInLand(0) {}

TowerOfControl::~TowerOfControl() {
   for (int i= 0 ; i < requests.size() ; i++)
      delete requests[i];
   delete airport;
   timer->remove(this);
   instance= nullptr;
}

long TowerOfControl::airplaneRequestLanding(Airplane* airplane) {
   Request* request= new LandingRequest(airplane);
   requests.push_back(request);
   verifyRequests();
   return timer->getActualTime();
}

long TowerOfControl::airplaneRequestTakeOff(Airplane* airplane) {
   Request* request= new TakeOffRequest(airplane);
   requests.push_back(request);
   verifyRequests();
   return timer->getActualTime();
}

void TowerOfControl::verifyRequests() {
   for (int i= 0; airport->airportIsAcessible() && i < requests.size(); ++i) {
      if (verifyRequest(*requests[i])) {
         delete requests[i];
         requests.erase(requests.begin()+i);
         break;
      } 
   }
}

bool TowerOfControl::verifyRequest(Request& request) {
   switch (request.getTypeRequest()) {
      case Request::LANDING:  return resolveLandingRequest(dynamic_cast<LandingRequest&>(request));
      case Request::TAKEOFF:  return resolveTakeOffRequest(dynamic_cast<TakeOffRequest&>(request));
   }
}

bool TowerOfControl::resolveLandingRequest(LandingRequest& landingRequest) {
   if (airplanesInLand < limitAirplanes) {
      if (airport->requestUseAirport(landingRequest.getAirplane())) {
         ++airplanesInLand;
         requestResolved(landingRequest);  
         return true;
      }   
   }
   return false;
}

bool TowerOfControl::resolveTakeOffRequest(TakeOffRequest& takeOffRequest) {
   if (airport->requestUseAirport(takeOffRequest.getAirplane())) {
      --airplanesInLand;
      requestResolved(takeOffRequest);
      return true;
   }
   return false;
}

void TowerOfControl::requestResolved(Request& request) {
   request.getAirplane()->allowedLanding(timer->getActualTime(), timer->getActualTime() + MyRandom::generateRandomValueBetween(5, 10));
}

void TowerOfControl::setLimitAirplanes(int limit)  {
   limitAirplanes= limit;
}

void TowerOfControl::changedAirport(Airplane* airplane) {
   for (int i= 0 ; i < requests.size() ; ++i) {
      if (requests[i]->getAirplane() ==  airplane) {
         delete requests[i];
         requests.erase(requests.begin() + i);
         break;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////

void TowerOfControl::updateTime(long time) {
   if (!requests.empty())
      verifyRequests();
}

///////////////////////////////////////////////////////////////////////////////

TowerOfControl* TowerOfControl::instance = nullptr;

TowerOfControl* TowerOfControl::getInstance() {
   if (!instance) {
      instance= new TowerOfControl();
      MyTimer::getTimer()->add(instance);
   }
   return instance;
}