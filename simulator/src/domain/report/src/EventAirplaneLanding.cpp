#include "EventAirplaneLanding.h"

EventAirplaneLanding::~EventAirplaneLanding() {}

EventAirplaneLanding::EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers) : Event(time) {
   airplaneName= _airplaneName;
   passengers= nPassengers;
}

EVENTTYPE EventAirplaneLanding::getTypeEvent() {
   return EVENTAIRPLANELANDING;
}

std::string EventAirplaneLanding::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " iniciando procedimento de pouso com " << passengers << " passeiros \n";
   return ss.str();
}

std::string EventAirplaneLanding::getAirplaneName() {
   return airplaneName;
}

int EventAirplaneLanding::getCountPassengers() {
   return passengers;
}
