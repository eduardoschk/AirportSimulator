#pragma once

#ifndef INCLUDED_EVENT_AIRPLANE_CHANGE_AIRPORT_H
#define INCLUDED_EVENT_AIRPLANE_CHANGE_AIRPORT_H

#include "event.h"

class EventAirplaneChangeAirport :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneChangeAirport() {}
   EventAirplaneChangeAirport(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_AIRPLANE_CHANGE_AIRPORT_H