#pragma once
#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>

class TowerOfControl;

class Airplane
{
private:
   std::string name;
   int passengers;
   TowerOfControl* towerOfControl;
   
   long timeRequestLanding;
   long timeLimitResponseLandingRequest;
   long timeAllowdLanding;
   long timeToNextFlight;

public:
   Airplane(std::string _name, int _passengers);
   virtual ~Airplane();

   void requestLandingToAirport();
   void requestTakeOffToAirport();

   void allowedLanding(long actualTime, long _timeToNextFlight);
   void changedAirport();
   
   std::string getName();
   int getCountPassengers();
   long getTimeLimitResponseLandingRequest();
   long getTimeAllowdLanding();
   long getTimeToNextFlight();

   void setName(std::string newName);
   void setCountPassengers(int newCountPassangers);
   void setTimeLimitResponseLandingRequest(long newTimeLimitResponseLandingRequest);
   void setTimeAllowdLanding(long newTimeAllowedLanding);
   void setTimeToNextFlight(long newTimeToNextFlight);
   long getTimeRequestLanding();
};

#endif //AIRPLANE_H