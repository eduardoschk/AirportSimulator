#include <sstream>
#include "EventAirplaneRequestLanding.h"

EventAirplaneRequestLanding::EventAirplaneRequestLanding(long time, std::string _airplaneName) : Event(time) 
{
   airplaneName= _airplaneName;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventAirplaneRequestLanding::getTypeEvent() 
{
   return EVENT_AIRPLANE_REQUEST_LANDING;
}

std::string EventAirplaneRequestLanding::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Avião " << airplaneName << " está solicitando pista para pousar \n";
   return ss.str();
}