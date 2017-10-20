#include <sstream>
#include "Log.h"
#include "ReportAirplanes.h"

std::string ReportAirplanes::generatingReport() 
{
   std::stringstream ss;
   int countingLandings= 0;
   std::deque<Event*> events= Log::getInstance()->getEvents();

   for(std::deque<Event*>::iterator i= events.begin(); i != events.end(); ++i) 
   {
      if ((dynamic_cast<Event*>(*i))->getTypeEvent() == EVENT_AIRPLANE_LANDING )
         ++countingLandings;
   }

   ss << "Quantidade de aviões que pousaram no aeroporto: " << countingLandings << "\n";
   return ss.str();
}