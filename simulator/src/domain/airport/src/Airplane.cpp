#include "Airplane.h"
#include "TowerOfControl.h"

// In seconds, each real second represents 4 minutes on simulator time

int limitTimeRequest = 8; 

Airplane::Airplane(std::string _name, int _passengers) : name(_name), passengers(_passengers), towerOfControl(TowerOfControl::getInstance()), timeLimitResponseLandingRequest(0), timeAllowdLanding(0), timeToNextFlight(0) {}

Airplane::~Airplane() {}

std::string Airplane::getName() {
   return name;
}

int Airplane::getCountPassengers() {
   return passengers;
}

void Airplane::requestLandingToAirport() {
   timeRequestLanding= towerOfControl->airplaneRequestLanding(this);
   timeLimitResponseLandingRequest = timeRequestLanding + limitTimeRequest;
}

void Airplane::requestTakeOffToAirport() {
   towerOfControl->airplaneRequestTakeOff(this);
}

void Airplane::allowedLanding(long time, long _timeToNextFlight) {
   timeAllowdLanding= time;
   timeToNextFlight= _timeToNextFlight;
}

void Airplane::changedAirport() {
   towerOfControl->changedAirport(this);
}

long Airplane::getTimeLimitResponseLandingRequest() {
   return timeLimitResponseLandingRequest;
}

long Airplane::getTimeToNextFlight() {
   return timeToNextFlight;
}

long Airplane::getTimeAllowdLanding() {
   return timeAllowdLanding;
}

void Airplane::setName(std::string newName) {
   name= newName;
}

void Airplane::setCountPassengers(int newCountPassangers) {
   passengers= newCountPassangers;
}

void Airplane::setTimeLimitResponseLandingRequest(long newTimeLimitResponseLandingRequest) {
   timeLimitResponseLandingRequest= newTimeLimitResponseLandingRequest;
}

void Airplane::setTimeAllowdLanding(long newTimeAllowedLanding) {
   timeAllowdLanding= newTimeAllowedLanding;
}

void Airplane::setTimeToNextFlight(long newTimeToNextFlight) {
   timeToNextFlight= newTimeToNextFlight;
}

long Airplane::getTimeRequestLanding() {
   return timeRequestLanding;
}
