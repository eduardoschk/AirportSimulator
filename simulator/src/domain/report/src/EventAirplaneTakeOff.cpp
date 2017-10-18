#include "EventAirplaneTakeOff.h"

EventAirplaneTakeOff::~EventAirplaneTakeOff() {}

EventAirplaneTakeOff::EventAirplaneTakeOff(long time, std::string _airplaneName, int nPassengers) : Event(time) {
   airplaneName= _airplaneName;
   passengers= nPassengers;
}

EVENTTYPE EventAirplaneTakeOff::getTypeEvent() {
   return EVENTAIRPLANETAKEOFF;
}

std::string EventAirplaneTakeOff::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " iniciando procedimento de decolagem na pista com " << passengers << " passeiros \n";
   return ss.str();
}

int EventAirplaneTakeOff::getCountPassengers() {
   return passengers;
}
