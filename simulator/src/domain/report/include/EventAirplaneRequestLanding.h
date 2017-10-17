#pragma once
#include "event.h"
#include <string>

class EventAirplaneRequestLanding :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneRequestLanding();
   EventAirplaneRequestLanding(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};