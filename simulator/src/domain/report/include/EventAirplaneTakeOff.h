#pragma once
#include "event.h"
#include <string>

class EventAirplaneTakeOff :
   public Event
{
private:
   std::string airplaneName;
   int passengers;

public:
   ~EventAirplaneTakeOff();
   EventAirplaneTakeOff(long time, std::string _airplaneName, int nPassengers);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};