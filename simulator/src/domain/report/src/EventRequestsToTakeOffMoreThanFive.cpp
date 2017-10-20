#include <sstream>
#include "EventRequestsToTakeOffMoreThanFive.h"

EventRequestsToTakeOffMoreThanFive::EventRequestsToTakeOffMoreThanFive(long time) : Event(time) {}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventRequestsToTakeOffMoreThanFive::getTypeEvent() 
{
   return EVENT_REQUESTS_TAKE_OFF_MORE_THAN_FIVE;
}

std::string EventRequestsToTakeOffMoreThanFive::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Existe mais de 5 requisições de decolagem aguardando serem resolvidas \n";
   return ss.str();
}