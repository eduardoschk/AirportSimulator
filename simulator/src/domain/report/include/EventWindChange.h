#pragma once

#ifndef INCLUDED_EVENT_WIND_CHANGE_H
#define INCLUDED_EVENT_WIND_CHANGE_H

#include "event.h"

class EventWindChange :
   public Event
{
private:
    std::string direction;
public:
   ~EventWindChange() {}
   EventWindChange(long time,  std::string newDirection);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_WIND_CHANGE_H