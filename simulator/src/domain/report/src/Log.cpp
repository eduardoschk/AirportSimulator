#include "Log.h"
#include "ReportController.h"
#include "EventFactory.h"

Log::~Log() {
   delete eventFactory;
   for (int i= 0 ; i < events.size() ; ++i)
      delete events[i];
   instance= nullptr;
   monitor= nullptr;
}

Log::Log() : eventFactory(new EventFactory()), monitor(nullptr) {}

///////////////////////////////////////////////////////////////////////////////

void Log::registryEvent(EVENTTYPE type, void* arg) {
   Event* newEvent= eventFactory->makeEvent(type, arg);
   if (monitor) 
      monitor->newEvent(newEvent);
   events.push_back(newEvent);
}

///////////////////////////////////////////////////////////////////////////////

void Log::initMonitoring(ReportController* controller) {
   monitor= controller;
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
