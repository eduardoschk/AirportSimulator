#include "TowerOfControl.h"
#include "Airplane.h"
#include "Request.h"
#include "Airport.h"
#include "MyTimer.h"
#include "MyRandom.h"
#include "Log.h"

TowerOfControl::TowerOfControl() : airport(Airport::getInstance()), airplanesInLand(0), log(Log::getInstance()) {}

TowerOfControl::~TowerOfControl() 
{
   for (int i= 0 ; i < requests.size() ; i++)
      delete requests[i];
   delete airport;
   instance= nullptr;
}

///////////////////////////////////////////////////////////////////////////////

void TowerOfControl::verifyAllRequests() 
{
   for (int i= 0; airport->airportIsAcessible() && i < requests.size(); ++i) 
   {
      if (verifyRequest(*requests[i])) 
      {
         delete requests[i];
         requests.erase(requests.begin()+i);
         break;
      } 
   }
}

///////////////////////////////////////////////////////////////////////////////

bool TowerOfControl::verifyRequest(Request& request) 
{
   switch (request.getTypeRequest()) 
   {
      case Request::REQUEST_LANDING:  return resolveLandingRequest(dynamic_cast<LandingRequest&>(request));
      case Request::REQUEST_TAKEOFF:  return resolveTakeOffRequest(dynamic_cast<TakeOffRequest&>(request));
   }
}

bool TowerOfControl::resolveLandingRequest(LandingRequest& landingRequest) 
{
   if (airplanesInLand < limitAirplanes) 
   {
      if (airport->requestUseAirport(landingRequest.getAirplane())) 
      {
         ++airplanesInLand;
         requestResolved(landingRequest);  
         log->registryEvent(EVENT_AIRPLANE_LANDING, landingRequest.getAirplane());
         verifyCriticalSituationCapacity();
         return true;
      }   
   }
   return false;
}

bool TowerOfControl::resolveTakeOffRequest(TakeOffRequest& takeOffRequest) 
{
   if (airport->requestUseAirport(takeOffRequest.getAirplane())) 
   {
      --airplanesInLand;
      requestResolved(takeOffRequest);
      log->registryEvent(EVENT_AIRPLANE_TAKE_OFF, takeOffRequest.getAirplane());
      return true;
   }
   return false;
}

void TowerOfControl::requestResolved(Request& request) 
{
   request.getAirplane()->allowedLanding(MyTimer::getActualTime(), MyTimer::getActualTime() + MyRandom::generateRandomValueBetween(5, 10));
}

///////////////////////////////////////////////////////////////////////////////

long TowerOfControl::airplaneRequestLanding(Airplane* airplane) 
{
   Request* request= new LandingRequest(airplane);
   log->registryEvent(EVENT_AIRPLANE_REQUEST_LANDING, &(airplane->getName()));
   requests.push_back(request);
   verifyAllRequests();
   verifyCriticalSituationWaiting();
   return MyTimer::getActualTime();
}

long TowerOfControl::airplaneRequestTakeOff(Airplane* airplane) 
{
   Request* request= new TakeOffRequest(airplane);
   log->registryEvent( EVENT_AIRPLANE_REQUEST_TAKE_OFF, &(airplane->getName()));
   requests.push_back(request);
   
   verifyAllRequests();
   verifyCriticalSituationWaiting();
   verifyCriticalSituationTakeOffPending();
   
   return MyTimer::getActualTime();
}

///////////////////////////////////////////////////////////////////////////////

void TowerOfControl::changedAirport(Airplane* airplane) 
{
   log->registryEvent(EVENT_AIRPLANE_CHANGE_AIRPORT, &(airplane->getName()));

   for (int i= 0 ; i < requests.size() ; ++i) 
   {
      if (requests[i]->getAirplane() ==  airplane) 
      {
         delete requests[i];
         requests.erase(requests.begin() + i);
         break;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////

void TowerOfControl::verifyCriticalSituationWaiting() 
{
   if (requests.size() > 5) 
      log->registryEvent(EVENT_AIRPLANES_WAITING_MORE_THAN_FIVE, nullptr);
}

void TowerOfControl::verifyCriticalSituationTakeOffPending() 
{
   int takeOffRequests= 0;
   for (std::deque<Request*>::iterator iter= requests.begin() ; takeOffRequests <= 5 && iter != requests.end() ; ++iter) 
   {
      if (dynamic_cast<Request*>(*iter)->getTypeRequest() == Request::REQUEST_TAKEOFF)
         takeOffRequests ++;
   }
   takeOffRequests > 5 ? log->registryEvent(EVENT_REQUESTS_TAKE_OFF_MORE_THAN_FIVE, nullptr) : NULL ;
}

void TowerOfControl::verifyCriticalSituationCapacity() 
{
   if (airplanesInLand >= (limitAirplanes * 0.7))
      log->registryEvent(EVENT_CAPACITY_MORE_THAN_SEVENTY, nullptr);
}

///////////////////////////////////////////////////////////////////////////////

int TowerOfControl::getNumberAirplanesOnGround() 
{
   return airplanesInLand;
}

void TowerOfControl::setLimitAirplanes(int limit)  
{
   limitAirplanes= limit;
}

///////////////////////////////////////////////////////////////////////////////

std::deque<Request*> TowerOfControl::getRequests() 
{
   return requests;
}

///////////////////////////////////////////////////////////////////////////////

TowerOfControl* TowerOfControl::instance = nullptr;

TowerOfControl* TowerOfControl::getInstance() 
{
   if (!instance) 
      instance= new TowerOfControl();
   return instance;
}