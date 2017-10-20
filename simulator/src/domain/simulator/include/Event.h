#pragma once

#ifndef INCLUDED_EVENT_H
#define INCLUDED_EVENT_H

#include <string>

enum EVENTTYPE {  
   EVENT_WIND_CHANGE, 
   EVENT_AIRPLANE_LANDING, 
   EVENT_AIRPLANE_CHANGE_AIRPORT, 
   EVENT_AIRPLANE_REQUEST_LANDING, 
   EVENT_AIRPLANE_REQUEST_TAKE_OFF, 
   EVENT_AIRPLANE_TAKE_OFF, 
   EVENT_RUN_WAY_FREE, 
   EVENT_AIRPLANES_WAITING_MORE_THAN_FIVE, 
   EVENT_CAPACITY_MORE_THAN_SEVENTY, 
   EVENT_REQUESTS_TAKE_OFF_MORE_THAN_FIVE 
};

class Event
{
protected:
   long timeEvent;
public:
   virtual ~Event() {}
   Event(long time) : timeEvent(time) {}

   virtual EVENTTYPE getTypeEvent() = 0;
   virtual std::string getEventToString();
};

#endif // INCLUDED_EVENT_H