#pragma once
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