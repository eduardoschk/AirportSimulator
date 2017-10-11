#pragma once

#include <string>

class TowerOfControl;
struct FlightPlan;
class Airplane
{
private:
   std::string name;
   int passengers;
   TowerOfControl* towerOfControl;
   
   long timeLimitResponseLandingRequest;
   long timeAllowdLanding;
   long timeToNextFlight;

public:
   Airplane(std::string _name, int _passengers);
   virtual ~Airplane();

   void requestLandingToAirport();
   void allowedLanding(long actualTime, long _timeToNextFlight);
   void changedAirport();
   
   std::string getName();
   int getCountPassengers();
   long getTimeLimitResponseLandingRequest();
   long getTimeAllowdLanding();
   long getTimeToNextFlight();
   void requestTakeOffToAirport();
};