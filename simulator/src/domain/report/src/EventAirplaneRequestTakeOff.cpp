#include <sstream>
#include "EventAirplaneRequestTakeOff.h"

EventAirplaneRequestTakeOff::EventAirplaneRequestTakeOff(long time, std::string _airplaneName) : Event(time) 
{
   airplaneName= _airplaneName;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventAirplaneRequestTakeOff::getTypeEvent() 
{
   return EVENT_AIRPLANE_REQUEST_TAKE_OFF;
}

std::string EventAirplaneRequestTakeOff::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Avião " << airplaneName << " está solicitando decolagem \n";
   return ss.str();
}