#pragma once

#ifndef EVENT_FACTORY_H
#define EVENT_FACTORY_H

#include "Event.h"
#include <exception>

class MyTimer;

class EventFactory
{
private:
   MyTimer* timer;

   class EventCreateError : public std::exception { virtual const char* what() const { return "Erro ao criar evento"; }  };

   Event* makeCapacityMoreThanSeventy();
   Event* makeRequestsTakeOffMoreThanFive();
   Event* makeAirplanesWaitingMoreThanFive();
   Event* makeAirplaneChangeAirportEvent(void* arg);

   Event* makeRunWayFreeEvent(void* arg);
   Event* makeChangeWindEvent(void* arg);
   Event* makeAirplaneLandingEvent(void* arg);
   Event* makeAirplaneTakeOffdEvent(void* arg);
   Event* makeAirplaneRequestAirportEvent(void* arg);
   Event* makeAirplaneRequestTakeOffEvent(void* arg);

   std::string getStringByArg(void* arg);

public:
   ~EventFactory();
   EventFactory();
   
   Event* makeEvent(EVENTTYPE type, void* arg);
};

#endif