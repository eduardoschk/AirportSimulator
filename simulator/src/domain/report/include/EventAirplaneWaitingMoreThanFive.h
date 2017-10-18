#pragma once
#include "event.h"
class EventAirplaneWaitingMoreThanFive :
   public Event
{
public:
   ~EventAirplaneWaitingMoreThanFive();
   EventAirplaneWaitingMoreThanFive(long time);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

