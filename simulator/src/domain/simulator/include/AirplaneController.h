#pragma once

#ifndef INCLUDED_AIRPLANE_CONTROLLER_H
#define INCLUDED_AIRPLANE_CONTROLLER_H

#include <deque>
#include "Observer.h"

class Airplane;
class MyTimer;

class AirplaneController :
   public Observer
{
private:
   MyTimer* timer;
   long timeToNewAirplane;
   std::deque<Airplane*> airplanes;   

   void generateAirplane();
   void calculateTimeNewAirplane();

   void checkUpdateInAirplanesGenerated();
   bool checkAirplaneHasAlreadyLanded(Airplane& airplane);
   bool checkAirplaneReadyToNextFlight(Airplane& airplane);
   bool checkTimeOutToAirportResponseRequest(Airplane& airplane);

   void timeOutRequestAirplane(Airplane& airplane);
   void airplaneReadyToTakeOff(Airplane& airplane);

public:
   ~AirplaneController();
   AirplaneController();

   void updateTime(const long time);
};

#endif // INCLUDED_AIRPLANE_CONTROLLER_H