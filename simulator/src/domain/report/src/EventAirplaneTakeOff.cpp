#include "EventAirplaneTakeOff.h"

EventAirplaneTakeOff::~EventAirplaneTakeOff() {}

EventAirplaneTakeOff::EventAirplaneTakeOff(long time, std::string _airplaneName, int nPassengers, Direction::DIRECTIONS _runWay) : Event(time) {
   airplaneName= _airplaneName;
   passengers= nPassengers;
   runWay= _runWay;
}

EVENTTYPE EventAirplaneTakeOff::getTypeEvent() {
   return AIRPLANETAKEOFF;
}

std::string EventAirplaneTakeOff::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avi�o " << airplaneName << " iniciando procedimento de decolagem na pista " << Direction::toString(runWay) << " com " << passengers << " passeiros";
   return ss.str();
}