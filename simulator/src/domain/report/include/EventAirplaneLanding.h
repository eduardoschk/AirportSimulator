#pragma once

#ifndef EVENT_AIRPLANE_LANDING_H
#define EVENT_AIRPLANE_LANDING_H

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
   std::string getAirplaneName();
   int getCountPassengers();
};

#endif // EVENT_AIRPLANE_LANDING_H