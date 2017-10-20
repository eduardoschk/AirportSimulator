#pragma once

#ifndef INCLUDED_EVENT_AIRPLANE_REQUEST_LANDING_H
#define INCLUDED_EVENT_AIRPLANE_REQUEST_LANDING_H

#include "event.h"

class EventAirplaneRequestLanding :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneRequestLanding() {}
   EventAirplaneRequestLanding(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_AIRPLANE_REQUEST_LANDING_H