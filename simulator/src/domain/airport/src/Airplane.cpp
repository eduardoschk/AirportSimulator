#include "Airplane.h"
#include "TowerOfControl.h"

int limitTimeRequest = 8;

Airplane::Airplane(std::string _name, int _passengers) : name(_name), passengers(_passengers), towerOfControl(TowerOfControl::getInstance()), timeLimitResponseLandingRequest(0), timeAllowdLanding(0), timeToNextFlight(0) {}

///////////////////////////////////////////////////////////////////////////////

void Airplane::requestLandingToAirport() 
{
   timeRequestLanding= towerOfControl->airplaneRequestLanding(this);
   timeLimitResponseLandingRequest = timeRequestLanding + limitTimeRequest;
}

void Airplane::requestTakeOffToAirport() 
{
   towerOfControl->airplaneRequestTakeOff(this);
}

///////////////////////////////////////////////////////////////////////////////

void Airplane::allowedLanding(long time, long _timeToNextFlight) 
{
   timeAllowdLanding= time;
   timeToNextFlight= _timeToNextFlight;
}

void Airplane::changedAirport() 
{
   towerOfControl->changedAirport(this);
}

///////////////////////////////////////////////////////////////////////////////

std::string Airplane::getName() 
{
   return name;
}

void Airplane::setName(std::string newName) 
{
   name= newName;
}

///////////////////////////////////////////////////////////////////////////////

int Airplane::getCountPassengers() 
{
   return passengers;
}

void Airplane::setCountPassengers(int newCountPassangers) 
{
   passengers= newCountPassangers;
}

///////////////////////////////////////////////////////////////////////////////

long Airplane::getTimeLimitResponseLandingRequest() {
   return timeLimitResponseLandingRequest;
}

void Airplane::setTimeLimitResponseLandingRequest(long newTimeLimitResponseLandingRequest) 
{
   timeLimitResponseLandingRequest= newTimeLimitResponseLandingRequest;
}

///////////////////////////////////////////////////////////////////////////////

long Airplane::getTimeToNextFlight() 
{
   return timeToNextFlight;
}

void Airplane::setTimeToNextFlight(long newTimeToNextFlight) 
{
   timeToNextFlight= newTimeToNextFlight;
}

///////////////////////////////////////////////////////////////////////////////

long Airplane::getTimeAllowdLanding() 
{
   return timeAllowdLanding;
}

void Airplane::setTimeAllowdLanding(long newTimeAllowedLanding) 
{
   timeAllowdLanding= newTimeAllowedLanding;
}

///////////////////////////////////////////////////////////////////////////////

long Airplane::getTimeRequestLanding() 
{
   return timeRequestLanding;
}