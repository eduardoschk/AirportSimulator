#pragma once

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <sstream>
#include "MyTimer.h"

enum EVENTTYPE {  EVENTWINDCHANGE, 
                  EVENTAIRPLANELANDING, 
                  EVENTAIRPLANECHANGEAIRPORT, 
                  EVENTAIRPLANEREQUESTLANDING, 
                  EVENTAIRPLANEREQUESTTAKEOFF, 
                  EVENTAIRPLANETAKEOFF, 
                  EVENTRUNWAYFREE, 
                  EVENTAIRPLANESWAITINGMORETHANFIVE, 
                  EVENTCAPACITYMORETHANSEVENTY, 
                  EVENTREQUESTSTAKEOFFMORETHANFIVE 
};

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

#endif // EVENT_H