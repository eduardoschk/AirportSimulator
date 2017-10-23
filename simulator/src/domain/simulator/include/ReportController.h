#pragma once

#ifndef INCLUDED_REPORT_CONTROLLER_H
#define INCLUDED_REPORT_CONTROLLER_H

#include <string>
#include <queue>

class Log;
class Event;
class Report;
class ReportFactory;

struct EventMonitoring { std::string message; };

enum REPORTTYPE {
   REPORT_AIRPLANES_LANDING, 
   REPORT_AIRPLANES_ON_GROUND, 
   REPORT_AIRPLANES_WAITING, 
   REPORT_CRITICAL_SITUATION, 
   REPORT_PASSENGERS, 
   REPORT_WIND
}; 

class ReportController
{
private:
   Log* log;
   ReportFactory* factory;
   std::queue<Event*> bufferEvents;

public:
   ReportController();
   ~ReportController();

   bool hasEvent();
   EventMonitoring getEvent();
   void newEvent(Event* event);

   std::string getReportResult(REPORTTYPE type);
   Report* generateReport(REPORTTYPE type);
}; 

#endif // INCLUDED_REPORT_CONTROLLER_H