#include <sstream>
#include "EventAirplaneLanding.h"

EventAirplaneLanding::EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers) : Event(time) 
{
   airplaneName= _airplaneName;
   passengers= nPassengers;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventAirplaneLanding::getTypeEvent() 
{
   return EVENT_AIRPLANE_LANDING;
}

std::string EventAirplaneLanding::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Avião " << airplaneName << " iniciando procedimento de pouso com " << passengers << " passeiros \n";
   return ss.str();
}

std::string EventAirplaneLanding::getAirplaneName() 
{
   return airplaneName;
}

int EventAirplaneLanding::getCountPassengers()
{
   return passengers;
}