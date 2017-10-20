#pragma once

#ifndef INCLUDED_EVENT_CAPACITY_MORE_THAN_SEVENTY
#define INCLUDED_EVENT_CAPACITY_MORE_THAN_SEVENTY

#include "event.h"

class EventCapacityMoreThanSeventy :
   public Event
{
public:
   ~EventCapacityMoreThanSeventy() {}
   EVENTTYPE getTypeEvent();

   std::string getEventToString();
   EventCapacityMoreThanSeventy(long time);
};

#endif // INCLUDED_EVENT_CAPACITY_MORE_THAN_SEVENTY