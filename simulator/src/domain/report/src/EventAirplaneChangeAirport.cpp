#include "EventAirplaneChangeAirport.h"
#include "MyTimer.h"
#include <sstream>

EventAirplaneChangeAirport::~EventAirplaneChangeAirport() {}

EventAirplaneChangeAirport::EventAirplaneChangeAirport(long time, std::string _airplaneName) : Event(time) {
   airplaneName= _airplaneName;
}

EVENTTYPE EventAirplaneChangeAirport::getTypeEvent() {
   return AIRPLANECHANGEAIRPORT;
}

std::string EventAirplaneChangeAirport::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " se encaminha a outro aeroporto por demora na liberação da pista";
   return ss.str();
}