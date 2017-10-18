#pragma once

#ifndef EVENT_RUN_WAY_RETURNS_FREE_H
#define EVENT_RUN_WAY_RETURNS_FREE_H

#include "event.h"

class EventRunWayReturnFree :
   public Event
{
private:
   std::string runWay;
public:
   ~EventRunWayReturnFree();
   EventRunWayReturnFree(long time, std::string idRunWay);

   virtual EVENTTYPE getTypeEvent();
   virtual std::string getEventToString();
};

#endif // EVENT_RUN_WAY_RETURNS_FREE_H