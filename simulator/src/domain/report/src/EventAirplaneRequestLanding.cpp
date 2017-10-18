#include "EventAirplaneRequestLanding.h"

EventAirplaneRequestLanding::~EventAirplaneRequestLanding() {}

EventAirplaneRequestLanding::EventAirplaneRequestLanding(long time, std::string _airplaneName) : Event(time) {
   airplaneName= _airplaneName;
}

EVENTTYPE EventAirplaneRequestLanding::getTypeEvent() {
   return EVENTAIRPLANEREQUESTLANDING;
}

std::string EventAirplaneRequestLanding::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " está solicitando pista para pousar \n";
   return ss.str();
}