#include <sstream>
#include "Log.h"
#include "ReportPassengers.h"
#include "EventAirplaneLanding.h"
#include "EventAirplaneTakeOff.h"

std::string ReportPassengers::generatingReport() 
{
   std::stringstream ss;
   int countPassengersThatArrived= 0;
   int countPassengersThatTraveled= 0;
   std::deque<Event*> events= Log::getInstance()->getEvents();

   for(std::deque<Event*>::iterator i= events.begin(); i != events.end(); ++i) 
   {
      if ((dynamic_cast<Event*>(*i))->getTypeEvent() == EVENT_AIRPLANE_LANDING )
         countPassengersThatArrived+= (dynamic_cast<EventAirplaneLanding*>(*i))->getCountPassengers();
      else if ((dynamic_cast<Event*>(*i))->getTypeEvent() == EVENT_AIRPLANE_TAKE_OFF)
         countPassengersThatTraveled+= (dynamic_cast<EventAirplaneTakeOff*>(*i))->getCountPassengers();
   }
   
   ss << "Número de passageiros que chegaram: " << countPassengersThatArrived << "\n"
      << "Número de passageiros que viajaram: " << countPassengersThatTraveled << "\n";

   return ss.str();
}
