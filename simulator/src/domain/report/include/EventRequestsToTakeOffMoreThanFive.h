#pragma once
#include "event.h"
class EventRequestsToTakeOffMoreThanFive :
   public Event
{
private:

public:
   ~EventRequestsToTakeOffMoreThanFive();
   EventRequestsToTakeOffMoreThanFive(long time);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

