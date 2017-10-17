#include "EventAirplaneLanding.h"

EventAirplaneLanding::~EventAirplaneLanding() {}

EventAirplaneLanding::EventAirplaneLanding(long time, std::string _airplaneName, int nPassengers, Direction::DIRECTIONS _runWay) : Event(time) {
   airplaneName= _airplaneName;
   passengers= nPassengers;
   runWay= _runWay;
}

EVENTTYPE EventAirplaneLanding::getTypeEvent() {
   return AIRPLANELANDING;
}

std::string EventAirplaneLanding::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " iniciando procedimento de pouso na pista " << Direction::toString(runWay) << " com " << passengers << " passeiros";
   return ss.str();
}