#include "Log.h"
#include "Report.h"
#include "ReportFactory.h"
#include "ReportController.h"

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

std::string ReportController::getReportResult(REPORTTYPE type)
{
   std::string result;
   Report* report= generateReport(type);

   result= report->generatingReport();
   delete report;
   return result;
}

Report* ReportController::generateReport(REPORTTYPE type)
{
   return factory->makeReport(type);
}
