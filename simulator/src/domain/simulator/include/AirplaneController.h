#pragma once

#include <deque>
#include "Observer.h"

class Airplane;
class MyTimer;

class AirplaneController :
   public Observer
{
private:
   std::deque<Airplane*> airplanes;

   long timeToNewAirplane;
   MyTimer* timer;

   void generateAirplane();
   void calculateTimeNewAirplane();
   void checkUpdateInAirplanesGenerated();
   bool checkAirplaneHasAlreadyLanded(Airplane* airplane);
   bool checkAirplaneReadyToNextFlight(Airplane* airplane);
   bool checkTimeOutToAirportResponseRequest(Airplane* airplane);

public:
   ~AirplaneController();
   AirplaneController();

   void updateTime(const long time);
};