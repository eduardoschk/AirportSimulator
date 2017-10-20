#pragma once

#ifndef INCLUDED_EVENT_REQUEST_TO_TAKE_OFF_MORE_THAN_FIVE
#define INCLUDED_EVENT_REQUEST_TO_TAKE_OFF_MORE_THAN_FIVE

#include "event.h"

class EventRequestsToTakeOffMoreThanFive :
   public Event
{
private:

public:
   ~EventRequestsToTakeOffMoreThanFive() {}
   EventRequestsToTakeOffMoreThanFive(long time);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_REQUEST_TO_TAKE_OFF_MORE_THAN_FIVE