#include "Log.h"
#include "EventFactory.h"
#include <iostream>

Log::~Log() {
   delete eventFactory;
   for (int i= 0 ; i < events.size() ; ++i)
      delete events[i];
   instance= nullptr;
}

Log::Log() : eventFactory(new EventFactory()) {}

void Log::registryEvent(EVENTTYPE type, void* arg) {
   Event* newEvent= eventFactory->makeEvent(type, arg);
   std::cout << newEvent->getEventToString();
   events.push_back(newEvent);
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Log* Log::instance= nullptr;

Log* Log::getInstance() {
   if (!instance)
      instance= new Log();
   return instance;
}
