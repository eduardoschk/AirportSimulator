#include "AirplaneController.h"
#include "MyTimer.h"
#include "MyRandom.h"
#include "Airplane.h"

//Para testes
#include <iostream>

AirplaneController::AirplaneController() : timer(MyTimer::getTimer()) {
   calculateTimeNewAirplane();
   timer->add(this);
}

AirplaneController::~AirplaneController() {
   for (int i= 0 ; i < airplanes.size() ; i++)
      delete airplanes[i];
   timer->remove(this);
}


void AirplaneController::updateTime(const long time) 
{
   if (time >= timeToNewAirplane) {
      generateAirplane();
   }
   checkUpdateInAirplanesGenerated();
}

void AirplaneController::generateAirplane()
{
   Airplane* newAirplane= new Airplane(MyRandom::generateNameAirplane(), MyRandom::generateRandomValueBetween(50, 220));
   std::cout << "Novo aviao chegando - " << newAirplane->getName() << "\n";
   airplanes.push_back(newAirplane);
   std::cout << "Solicitando pouso - " << newAirplane->getName() << "\n\n";
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
            std::cout << "Solicitando decolagem - " << airplane->getName() << "\n\n";
            
            airplane->requestTakeOffToAirport();  
            airplanes.erase( airplanes.begin() + i );
         }
      } else {
         if (checkTimeOutToAirportResponseRequest(airplane)) {
            std::cout << "Aviao tempo demais esperando - " << airplane->getName() << "\n\n"; 
            
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