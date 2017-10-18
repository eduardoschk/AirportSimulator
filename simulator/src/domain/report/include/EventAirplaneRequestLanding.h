#pragma once

#ifndef EVENT_AIRPLANE_REQUEST_LANDING_H
#define EVENT_AIRPLANE_REQUEST_LANDING_H

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

#endif // EVENT_AIRPLANE_REQUEST_LANDING_H