#pragma once
#ifndef INCLUDED_AIRPLANE_H
#define INCLUDED_AIRPLANE_H

#include <string>

class TowerOfControl;

class Airplane
{
private:
   int passengers;
   std::string name;
   TowerOfControl* towerOfControl;
   
   long timeRequestLanding;
   long timeLimitResponseLandingRequest;

   long timeAllowdLanding;
   long timeToNextFlight;

public:
   Airplane(std::string _name, int _passengers);
   virtual ~Airplane() {}

   void requestLandingToAirport();
   void requestTakeOffToAirport();

   void changedAirport();
   void allowedLanding(long actualTime, long _timeToNextFlight);
   
   std::string getName();
   void setName(std::string newName);

   int getCountPassengers();
   void setCountPassengers(int newCountPassangers);

   long getTimeLimitResponseLandingRequest();
   void setTimeLimitResponseLandingRequest(long newTimeLimitResponseLandingRequest);
   
   long getTimeAllowdLanding();
   void setTimeAllowdLanding(long newTimeAllowedLanding);

   long getTimeToNextFlight();
   void setTimeToNextFlight(long newTimeToNextFlight);

   long getTimeRequestLanding();
};

#endif // INCLUDED_AIRPLANE_H