#include <sstream>
#include "Log.h"
#include "ReportCriticalSituation.h"

std::string ReportCriticalSituation::generatingReport() 
{
   std::stringstream ss;
   std::deque<Event*> events= Log::getInstance()->getEvents();

   ss << "Situações Criticas \n";
   for (std::deque<Event*>::iterator iter= events.begin() ; iter != events.end() ; ++iter) 
   {
      Event* e= dynamic_cast<Event*>(*iter);
      if (e->getTypeEvent() == EVENT_REQUESTS_TAKE_OFF_MORE_THAN_FIVE || e->getTypeEvent() == EVENT_AIRPLANE_CHANGE_AIRPORT || e->getTypeEvent() == EVENT_AIRPLANES_WAITING_MORE_THAN_FIVE || e->getTypeEvent() == EVENT_CAPACITY_MORE_THAN_SEVENTY)
         ss << e->getEventToString();
   }
   
   return ss.str();
}