#include "ReportAirplanes.h"
#include "Log.h"

ReportAirplanes::~ReportAirplanes() {}

ReportAirplanes::ReportAirplanes() {}

std::string ReportAirplanes::generatingReport() {
   std::stringstream ss;
   int countingLandings= 0;
   std::deque<Event*> events= Log::getInstance()->getEvents();

   for(std::deque<Event*>::iterator i= events.begin(); i != events.end(); ++i) {
      if ((dynamic_cast<Event*>(*i))->getTypeEvent() == EVENTAIRPLANELANDING )
         ++countingLandings;
   }

   ss << "Quantidade de aviões que pousaram no aeroporto: " << countingLandings << "\n";
   return ss.str();
}