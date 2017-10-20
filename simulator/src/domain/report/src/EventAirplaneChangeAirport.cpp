#include <sstream>
#include "MyTimer.h"
#include "EventAirplaneChangeAirport.h"

EventAirplaneChangeAirport::EventAirplaneChangeAirport(long time, std::string _airplaneName) : Event(time) 
{
   airplaneName= _airplaneName;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventAirplaneChangeAirport::getTypeEvent() 
{
   return EVENT_AIRPLANE_CHANGE_AIRPORT;
}

std::string EventAirplaneChangeAirport::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Avi�o " << airplaneName << " se encaminha a outro aeroporto por demora na libera��o da pista \n";
   return ss.str();
}