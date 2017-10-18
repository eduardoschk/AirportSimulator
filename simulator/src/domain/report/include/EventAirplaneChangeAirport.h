#pragma once

#ifndef EVENT_AIRPLANE_CHANGE_AIRPORT_H
#define EVENT_AIRPLANE_CHANGE_AIRPORT_H

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

#endif // EVENT_AIRPLANE_CHANGE_AIRPORT_H