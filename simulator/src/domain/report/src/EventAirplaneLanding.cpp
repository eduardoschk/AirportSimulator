#include "EventAirplaneLanding.h"

EventAirplaneLanding::~EventAirplaneLanding() {}

EventAirplaneLanding::EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers) : Event(time) {
   airplaneName= _airplaneName;
   passengers= nPassengers;
}

EVENTTYPE EventAirplaneLanding::getTypeEvent() {
   return AIRPLANELANDING;
}

std::string EventAirplaneLanding::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " iniciando procedimento de pouso com " << passengers << " passeiros";
   return ss.str();
}