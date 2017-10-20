#include "MyTimer.h"
#include "MyRandom.h"
#include "Airplane.h"
#include "AirplaneController.h"

int minPassengers= 50;
int maxPassengers= 220;

AirplaneController::~AirplaneController() 
{
   for (int i= 0 ; i < airplanes.size() ; i++)
      delete airplanes[i];
   timer->removeObserver(this);
}

AirplaneController::AirplaneController() : timer(MyTimer::getTimer()) 
{
   calculateTimeNewAirplane();
   timer->addObserver(this);
}

///////////////////////////////////////////////////////////////////////////////

void AirplaneController::generateAirplane() 
{
   Airplane* newAirplane= new Airplane(MyRandom::generateNameAirplane(), MyRandom::generateRandomValueBetween(minPassengers, maxPassengers));
   
   calculateTimeNewAirplane();
   airplanes.push_back(newAirplane);
   newAirplane->requestLandingToAirport();
}

void AirplaneController::calculateTimeNewAirplane() 
{
   timeToNewAirplane= timer->getActualTime() + MyRandom::generateRandomValueBetween(1, 4);
}

///////////////////////////////////////////////////////////////////////////////

void AirplaneController::checkUpdateInAirplanesGenerated()
{
   for (int i= 0 ; i < airplanes.size() ; ++i)  
   {
      if (checkAirplaneHasAlreadyLanded(*airplanes[i])) 
      {
         if (checkAirplaneReadyToNextFlight(*airplanes[i])) 
         {
            airplaneReadyToTakeOff(*airplanes[i]);
            airplanes.erase( airplanes.begin() + i );
         }
      } else 
      {
         if (checkTimeOutToAirportResponseRequest(*airplanes[i])) 
         {
            timeOutRequestAirplane(*airplanes[i]);
            airplanes.erase( airplanes.begin() + i );
         }
      }
   }
}

bool AirplaneController::checkAirplaneHasAlreadyLanded(Airplane& airplane) 
{
   return airplane.getTimeAllowdLanding() > 0;
}

bool AirplaneController::checkAirplaneReadyToNextFlight(Airplane& airplane) 
{
   return timer->getActualTime() == airplane.getTimeToNextFlight();
}

bool AirplaneController::checkTimeOutToAirportResponseRequest(Airplane& airplane) 
{
   return airplane.getTimeLimitResponseLandingRequest() == timer->getActualTime();
}

///////////////////////////////////////////////////////////////////////////////

void AirplaneController::timeOutRequestAirplane(Airplane& airplane)
{
   airplane.changedAirport();
   delete &airplane;
}

void AirplaneController::airplaneReadyToTakeOff(Airplane& airplane)
{
   airplane.setCountPassengers(MyRandom::generateRandomValueBetween(minPassengers, maxPassengers));
   airplane.requestTakeOffToAirport();
}

///////////////////////////////////////////////////////////////////////////////

void AirplaneController::updateTime(const long time)  
{
   if (time >= timeToNewAirplane)
      generateAirplane();
   checkUpdateInAirplanesGenerated();
}