#pragma once
#include "event.h"
#include <string>

class EventAirplaneLanding :
   public Event
{
private:
   std::string airplaneName;
   int passengers;

public:
   ~EventAirplaneLanding();
   EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};