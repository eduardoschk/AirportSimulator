#pragma once

#ifndef INCLUDED_EVENT_RUN_WAY_RETURNS_FREE_H
#define INCLUDED_EVENT_RUN_WAY_RETURNS_FREE_H

#include "event.h"

class EventRunWayReturnFree :
   public Event
{
private:
   std::string runWay;
public:
   ~EventRunWayReturnFree() {}
   EventRunWayReturnFree(long time, std::string idRunWay);

   EVENTTYPE getTypeEvent();
   std::string getEventToString();
};

#endif // INCLUDED_EVENT_RUN_WAY_RETURNS_FREE_H