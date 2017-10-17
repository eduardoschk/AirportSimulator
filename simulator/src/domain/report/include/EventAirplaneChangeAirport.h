#pragma once
#include "event.h"
#include <string>

class EventAirplaneChangeAirport :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneChangeAirport();
   EventAirplaneChangeAirport(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};