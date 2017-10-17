#pragma once
#include "Event.h"

class MyTimer;

class EventFactory
{
private:
   MyTimer* timer;

   Event* makeChangeWindEvent(void* arg);
   Event* makeAirplaneRequestAirportEvent(void* arg);
   Event* makeAirplaneChangeAirportEvent(void* arg);
   Event* makeAirplaneRequestTakeOffEvent(void* arg);
   Event* makeAirplaneTakeOffdEvent(void* arg);
   Event* makeRunWayFreeEvent(void* arg);
   Event* makeAirplaneLandingEvent(void* arg);
   std::string getStringByArg(void* arg);

public:
   ~EventFactory();
   EventFactory();

   Event* makeEvent(EVENTTYPE type, void* arg[]);
};
