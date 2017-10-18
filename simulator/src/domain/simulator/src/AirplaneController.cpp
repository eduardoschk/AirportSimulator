#include "AirplaneController.h"
#include "MyTimer.h"
#include "MyRandom.h"
#include "Airplane.h"
#include "Log.h"

int minPassengers= 50;
int maxPassengers= 220;

AirplaneController::AirplaneController() : timer(MyTimer::getTimer()), log(Log::getInstance()) {
   calculateTimeNewAirplane();
   timer->add(this);
}

AirplaneController::~AirplaneController() {
   for (int i= 0 ; i < airplanes.size() ; i++)
      delete airplanes[i];
   timer->remove(this);
}


void AirplaneController::updateTime(const long time)  {
   if (time >= timeToNewAirplane)
      generateAirplane();
   checkUpdateInAirplanesGenerated();
}

void AirplaneController::generateAirplane() {
   Airplane* newAirplane= new Airplane(MyRandom::generateNameAirplane(), MyRandom::generateRandomValueBetween(minPassengers, maxPassengers));
   airplanes.push_back(newAirplane);
   log->registryEvent(EVENTAIRPLANEREQUESTLANDING, &(newAirplane->getName()));
   newAirplane->requestLandingToAirport();
   calculateTimeNewAirplane();
}

void AirplaneController::calculateTimeNewAirplane() {
   timeToNewAirplane= timer->getActualTime() + MyRandom::generateRandomValueBetween(1, 4);
}

void AirplaneController::checkUpdateInAirplanesGenerated()
{
   for (int i= 0 ; i < airplanes.size() ; ++i)  {
      Airplane* airplane= airplanes[i];
      if (checkAirplaneHasAlreadyLanded(airplane)) {
         if (checkAirplaneReadyToNextFlight(airplane)) {
            log->registryEvent( EVENTAIRPLANEREQUESTTAKEOFF, &(airplane->getName()));

            airplane->setCountPassengers(MyRandom::generateRandomValueBetween(minPassengers, maxPassengers));
            airplane->requestTakeOffToAirport();  
            airplanes.erase( airplanes.begin() + i );
         }
      } else {
         if (checkTimeOutToAirportResponseRequest(airplane)) {
            log->registryEvent(EVENTAIRPLANECHANGEAIRPORT, &(airplane->getName()));
            
            airplane->changedAirport();
            delete airplane;
            airplanes.erase( airplanes.begin() + i );
         }
      }
   }
}

bool AirplaneController::checkAirplaneHasAlreadyLanded(Airplane* airplane) {
   return airplane->getTimeAllowdLanding() > 0;
}

bool AirplaneController::checkAirplaneReadyToNextFlight(Airplane* airplane) {
   return timer->getActualTime() == airplane->getTimeToNextFlight();
}

bool AirplaneController::checkTimeOutToAirportResponseRequest(Airplane* airplane) {
   return airplane->getTimeLimitResponseLandingRequest() == timer->getActualTime();
}