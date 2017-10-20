#include <sstream>
#include "EventAirplaneWaitingMoreThanFive.h"

EventAirplaneWaitingMoreThanFive::EventAirplaneWaitingMoreThanFive(long time) : Event(time) {}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventAirplaneWaitingMoreThanFive::getTypeEvent() 
{
   return EVENT_AIRPLANES_WAITING_MORE_THAN_FIVE;
}

std::string EventAirplaneWaitingMoreThanFive::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Existem mais que 5 aviões aguardando liberação da pista para pouso \n";
   return ss.str();
}