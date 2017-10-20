#include <sstream>
#include "EventAirplaneTakeOff.h"

EventAirplaneTakeOff::EventAirplaneTakeOff(long time, std::string _airplaneName, int nPassengers) : Event(time) 
{
   airplaneName= _airplaneName;
   passengers= nPassengers;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventAirplaneTakeOff::getTypeEvent() 
{
   return EVENT_AIRPLANE_TAKE_OFF;
}

std::string EventAirplaneTakeOff::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Avião " << airplaneName << " iniciando procedimento de decolagem na pista com " << passengers << " passeiros \n";
   return ss.str();
}

int EventAirplaneTakeOff::getCountPassengers() 
{
   return passengers;
}
