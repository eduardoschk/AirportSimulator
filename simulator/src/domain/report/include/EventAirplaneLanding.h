#pragma once
#include "event.h"
#include <string>
#include "Direction.h"

class EventAirplaneLanding :
   public Event
{
private:
   std::string airplaneName;
   int passengers;
   Direction::DIRECTIONS runWay;

public:
   ~EventAirplaneLanding();
   EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers, Direction::DIRECTIONS _runWay);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};