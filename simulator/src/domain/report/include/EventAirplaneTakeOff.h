#pragma once

#ifndef INCLUDED_EVENT_AIRPLANE_TAKE_OFF_H
#define INCLUDED_EVENT_AIRPLANE_TAKE_OFF_H

#include "event.h"

class EventAirplaneTakeOff :
   public Event
{
private:
   std::string airplaneName;
   int passengers;

public:
   ~EventAirplaneTakeOff() {}
   EventAirplaneTakeOff(long time, std::string _airplaneName, int nPassengers);

   int getCountPassengers();
   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_AIRPLANE_TAKE_OFF_H