#include <sstream>
#include "Log.h"
#include "ReportWind.h"

std::string ReportWind::generatingReport() 
{
   std::stringstream ss;
   std::deque<Event*> events= Log::getInstance()->getEvents();
   
   for (std::deque<Event*>::iterator iter= events.begin() ; iter != events.end() ; ++iter) 
   {
      Event* e= dynamic_cast<Event*>(*iter);
      if (e->getTypeEvent() == EVENT_WIND_CHANGE)
         ss << e->getEventToString();
   }

   return ss.str();
}
