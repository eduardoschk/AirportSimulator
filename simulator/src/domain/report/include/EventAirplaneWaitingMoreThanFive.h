#pragma once

#ifndef INCLUDED_EVENT_AIRPLANE_WAITING_MORE_THAN_FIVE_H
#define INCLUDED_EVENT_AIRPLANE_WAITING_MORE_THAN_FIVE_H

#include "event.h"

class EventAirplaneWaitingMoreThanFive :
   public Event
{
public:
   ~EventAirplaneWaitingMoreThanFive() {}
   EventAirplaneWaitingMoreThanFive(long time);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_AIRPLANE_WAITING_MORE_THAN_FIVE_H