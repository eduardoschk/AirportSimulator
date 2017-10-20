#pragma once

#ifndef INCLUDED_LOG_H
#define INCLUDED_LOG_H

#include "Event.h"
#include <deque>

class EventFactory;
class ReportController;

class Log 
{
private:
   EventFactory* eventFactory;
   std::deque<Event*> events;
   ReportController* monitor;

   static Log* instance;

public:
   ~Log();
   Log();

   void registryEvent(EVENTTYPE type, void* arg);

   std::deque<Event*> getEvents() { return events; }

   void initMonitoring(ReportController* controller);
   void stopMonitoring();

   static Log* getInstance();
};

#endif // INCLUDED_LOG_H