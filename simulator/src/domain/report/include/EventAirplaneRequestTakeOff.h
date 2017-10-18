#pragma once

#ifndef EVENT_AIRPLANE_REQUEST_TAKE_OFF_H
#define EVENT_AIRPLANE_REQUEST_TAKE_OFF_H

#include "Event.h"
#include <string>

class EventAirplaneRequestTakeOff :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneRequestTakeOff();
   EventAirplaneRequestTakeOff(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // EVENT_AIRPLANE_REQUEST_TAKE_OFF_H