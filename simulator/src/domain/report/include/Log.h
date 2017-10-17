#pragma once

#include "Event.h"
#include <queue>

class EventFactory;

class Log 
{
private:
   EventFactory *eventFactory;
   std::queue<Event*> events;

   static Log* instance;

public:
   ~Log();
   Log();

   void registryEvent(EVENTTYPE type, void* arg);

   static Log* getInstance();
};