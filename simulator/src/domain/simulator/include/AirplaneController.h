#pragma once

#ifndef AIRPLANE_CONTROLLER_H
#define AIRPLANE_CONTROLLER_H

#include <deque>
#include "Observer.h"

class Airplane;
class MyTimer;
class Log;

class AirplaneController :
   public Observer
{
private:
   std::deque<Airplane*> airplanes;

   long timeToNewAirplane;
   MyTimer* timer;

   Log* log;

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

#endif //AIRPLANE_CONTROLLER_H