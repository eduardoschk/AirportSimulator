#pragma once
#include "Event.h"
#include <string>

class EventAirplaneRequestTakeOff :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneRequestTakeOff();
   EventAirplaneRequestTakeOff(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};