#pragma once

#include <string>
#include <sstream>
#include "MyTimer.h"

enum EVENTTYPE {WINDCHANGE, AIRPLANELANDING, AIRPLANECHANGEAIRPORT, AIRPLANEREQUESTLANDING, AIRPLANEREQUESTTAKEOFF, AIRPLANETAKEOFF, RUNWAYFREE };

class Event
{
protected:
   long timeEvent;
public:
   virtual ~Event() {}
   Event(long time) : timeEvent(time) {}

   virtual EVENTTYPE getTypeEvent() = 0;
   virtual std::string getEventToString() {
      std::stringstream ss;
      ss << "-- Hora: "<< MyTimer::getDateOnTimestamp(timeEvent) << " -------- ";
      return ss.str();
   }
};