#pragma once
#include "event.h"
#include <string>
#include "Direction.h"

class EventAirplaneTakeOff :
   public Event
{
private:
   std::string airplaneName;
   int passengers;
   Direction::DIRECTIONS runWay;

public:
   ~EventAirplaneTakeOff();
   EventAirplaneTakeOff(long time, std::string _airplaneName, int nPassengers, Direction::DIRECTIONS _runWay);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};