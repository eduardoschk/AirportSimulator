#include <sstream>
#include "EventCapacityMoreThanSeventy.h"

EventCapacityMoreThanSeventy::EventCapacityMoreThanSeventy(long time) : Event(time) {}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventCapacityMoreThanSeventy::getTypeEvent() 
{
   return EVENT_CAPACITY_MORE_THAN_SEVENTY;
}

std::string EventCapacityMoreThanSeventy::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Capacidade de aviões em solo do aeroporto atingida \n";
   return ss.str();
}