#include "TowerOfControl.h"
#include "Airplane.h"
#include "Request.h"
#include "Airport.h"
#include "MyTimer.h"
#include "MyRandom.h"
#include "Log.h"

TowerOfControl::TowerOfControl() : airport(Airport::getInstance()), airplanesInLand(0), log(Log::getInstance()) {}

TowerOfControl::~TowerOfControl() {
   for (int i= 0 ; i < requests.size() ; i++)
      delete requests[i];
   delete airport;
   instance= nullptr;
}

int TowerOfControl::getNumberAirplanesOnGround() {
   return airplanesInLand;
}

long TowerOfControl::airplaneRequestLanding(Airplane* airplane) {
   Request* request= new LandingRequest(airplane);
   requests.push_back(request);
   verifyRequests();
   return MyTimer::getActualTime();
}

long TowerOfControl::airplaneRequestTakeOff(Airplane* airplane) {
   Request* request= new TakeOffRequest(airplane);
   requests.push_back(request);
   verifyRequests();
   return MyTimer::getActualTime();
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
         log->registryEvent(EVENTAIRPLANELANDING, landingRequest.getAirplane());
         return true;
      }   
   }
   return false;
}

bool TowerOfControl::resolveTakeOffRequest(TakeOffRequest& takeOffRequest) {
   if (airport->requestUseAirport(takeOffRequest.getAirplane())) {
      --airplanesInLand;
      requestResolved(takeOffRequest);
      log->registryEvent(EVENTAIRPLANETAKEOFF, takeOffRequest.getAirplane());
      return true;
   }
   return false;
}

void TowerOfControl::requestResolved(Request& request) {
   request.getAirplane()->allowedLanding(MyTimer::getActualTime(), MyTimer::getActualTime() + MyRandom::generateRandomValueBetween(5, 10));
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

std::deque<Request*> TowerOfControl::getRequests() {
   return requests;
}

///////////////////////////////////////////////////////////////////////////////

TowerOfControl* TowerOfControl::instance = nullptr;

TowerOfControl* TowerOfControl::getInstance() {
   if (!instance) 
      instance= new TowerOfControl();
   return instance;
}