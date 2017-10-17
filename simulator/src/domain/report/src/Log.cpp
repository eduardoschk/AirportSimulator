#include "Log.h"
#include "EventFactory.h"
#include <iostream>

Log::~Log() {}

Log::Log() : eventFactory(new EventFactory()) {}

void Log::registryEvent(EVENTTYPE type, void* arg) {
   Event* newEvent= eventFactory->makeEvent(type, arg);
   std::cout << newEvent->getEventToString() << std::endl;
   events.push(newEvent);
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
