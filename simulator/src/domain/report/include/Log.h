#pragma once

#ifndef LOG_H
#define LOG_H

#include "Event.h"
#include <deque>

class EventFactory;

class Log 
{
private:
   EventFactory *eventFactory;
   std::deque<Event*> events;

   static Log* instance;

public:
   ~Log();
   Log();

   void registryEvent(EVENTTYPE type, void* arg);
   std::deque<Event*> getEvents() { return events; }

   static Log* getInstance();
};

#endif // LOG_H