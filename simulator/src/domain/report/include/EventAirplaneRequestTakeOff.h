#pragma once

#ifndef INCLUDED_EVENT_AIRPLANE_REQUEST_TAKE_OFF_H
#define INCLUDED_EVENT_AIRPLANE_REQUEST_TAKE_OFF_H

#include "Event.h"

class EventAirplaneRequestTakeOff :
   public Event
{
private:
   std::string airplaneName;
public:
   ~EventAirplaneRequestTakeOff() {}
   EventAirplaneRequestTakeOff(long time, std::string _airplaneName);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_AIRPLANE_REQUEST_TAKE_OFF_H