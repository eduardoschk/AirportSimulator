#pragma once

#ifndef INCLUDED_EVENT_AIRPLANE_LANDING_H
#define INCLUDED_EVENT_AIRPLANE_LANDING_H

#include "event.h"

class EventAirplaneLanding :
   public Event
{
private:
   std::string airplaneName;
   int passengers;

public:
   ~EventAirplaneLanding() {}
   EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers);

   EVENTTYPE getTypeEvent();
   int getCountPassengers();
   std::string getAirplaneName();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_AIRPLANE_LANDING_H