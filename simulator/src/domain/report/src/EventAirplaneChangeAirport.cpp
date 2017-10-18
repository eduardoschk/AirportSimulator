#include "EventAirplaneChangeAirport.h"
#include "MyTimer.h"
#include <sstream>

EventAirplaneChangeAirport::~EventAirplaneChangeAirport() {}

EventAirplaneChangeAirport::EventAirplaneChangeAirport(long time, std::string _airplaneName) : Event(time) {
   airplaneName= _airplaneName;
}

EVENTTYPE EventAirplaneChangeAirport::getTypeEvent() {
   return EVENTAIRPLANECHANGEAIRPORT;
}

std::string EventAirplaneChangeAirport::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avi�o " << airplaneName << " se encaminha a outro aeroporto por demora na libera��o da pista \n";
   return ss.str();
}