#pragma once

#ifndef EVENT_WIND_CHANGE_H
#define EVENT_WIND_CHANGE_H

#include "event.h"
#include "Direction.h"

class EventWindChange :
   public Event
{
private:
   Direction::DIRECTIONS direction;
public:
   ~EventWindChange();
   EventWindChange(long time, Direction::DIRECTIONS newDirection);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // EVENT_WIND_CHANGE_H