#pragma once
#include "event.h"
class EventCapacityMoreThanSeventy :
   public Event
{
public:
   ~EventCapacityMoreThanSeventy();
   EVENTTYPE getTypeEvent();

   std::string getEventToString();
   EventCapacityMoreThanSeventy(long time);
};