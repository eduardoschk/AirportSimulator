#include <sstream>
#include "EventWindChange.h"

EventWindChange::EventWindChange(long time,  std::string newDirection) : Event(time) 
{
   direction= newDirection;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventWindChange::getTypeEvent() 
{
   return EVENT_WIND_CHANGE;
}

std::string EventWindChange::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Vento alterado para " << direction << "\n";
   return ss.str();
}