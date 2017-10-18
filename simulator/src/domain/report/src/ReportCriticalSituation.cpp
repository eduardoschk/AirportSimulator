#include "ReportCriticalSituation.h"
#include "Log.h"

ReportCriticalSituation::ReportCriticalSituation() {}

ReportCriticalSituation::~ReportCriticalSituation() {}

std::string ReportCriticalSituation::generatingReport() {
   std::stringstream ss;
   std::deque<Event*> events= Log::getInstance()->getEvents();

   ss << "Situações Criticas \n";
   for (std::deque<Event*>::iterator iter= events.begin() ; iter != events.end() ; ++iter) {
      Event* e= dynamic_cast<Event*>(*iter);
      if (e->getTypeEvent() == EVENTREQUESTSTAKEOFFMORETHANFIVE || e->getTypeEvent() == EVENTAIRPLANECHANGEAIRPORT || e->getTypeEvent() == EVENTAIRPLANESWAITINGMORETHANFIVE || e->getTypeEvent() == EVENTCAPACITYMORETHANSEVENTY)
         ss << e->getEventToString();
   }
   
   return ss.str();
}