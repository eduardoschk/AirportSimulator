#pragma once
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