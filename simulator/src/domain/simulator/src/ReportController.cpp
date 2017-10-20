#include "ReportController.h"
#include "ReportFactory.h"
#include "Log.h"

ReportController::~ReportController() 
{
   delete factory;
   delete log;
}

ReportController::ReportController() : log(Log::getInstance()), factory(new ReportFactory())
{
   log->initMonitoring(this);
}

///////////////////////////////////////////////////////////////////////////////

EventMonitoring ReportController::getEvent()
{
   EventMonitoring eventMonitoring;
   eventMonitoring.message= bufferEvents.front()->getEventToString();
   bufferEvents.pop();
   return eventMonitoring;
}

bool ReportController::hasEvent()
{
   return bufferEvents.size() > 0;
}

void ReportController::newEvent(Event* evento) 
{
   bufferEvents.push(evento);
}

///////////////////////////////////////////////////////////////////////////////

Report* ReportController::generateReport(REPORTTYPE type) 
{
   return factory->makeReport(type);
}