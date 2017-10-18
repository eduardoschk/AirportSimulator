#include "ReportPassengers.h"
#include <sstream>
#include <deque>
#include "Log.h"
#include "EventAirplaneLanding.h"
#include "EventAirplaneTakeOff.h"

std::string ReportPassengers::generatingReport() {
   std::stringstream ss;
   int countPassengersThatTraveled;
   int countPassengersThatArrived = countPassengersThatTraveled= 0;
  
   std::deque<Event*> events= Log::getInstance()->getEvents();

   for(std::deque<Event*>::iterator i= events.begin(); i != events.end(); ++i) {
      if ((dynamic_cast<Event*>(*i))->getTypeEvent() == EVENTAIRPLANELANDING )
         countPassengersThatArrived+= (dynamic_cast<EventAirplaneLanding*>(*i))->getCountPassengers();
      else if ((dynamic_cast<Event*>(*i))->getTypeEvent() == EVENTAIRPLANETAKEOFF)
         countPassengersThatArrived+= (dynamic_cast<EventAirplaneTakeOff*>(*i))->getCountPassengers();
   }
   
   ss << "Número de passageiros que chegaram: " << countPassengersThatArrived << "\n";
   ss << "Número de passageiros que viajaram: " << countPassengersThatTraveled << "\n";
   return ss.str();
}
