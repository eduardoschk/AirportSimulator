#include "ReportWind.h"
#include "Log.h"

ReportWind::~ReportWind() {}

ReportWind::ReportWind() {}

std::string ReportWind::generatingReport() {
   std::stringstream ss;
   std::deque<Event*> events= Log::getInstance()->getEvents();
   
   for (std::deque<Event*>::iterator iter= events.begin() ; iter != events.end() ; ++iter) {
      Event* e= dynamic_cast<Event*>(*iter);
      if (e->getTypeEvent() == EVENTWINDCHANGE)
         ss << e->getEventToString();
   }

   return ss.str();
}
