#include "EventAirplaneRequestTakeOff.h"

EventAirplaneRequestTakeOff::~EventAirplaneRequestTakeOff() {}

EventAirplaneRequestTakeOff::EventAirplaneRequestTakeOff(long time, std::string _airplaneName) : Event(time) {
   airplaneName= _airplaneName;
}


EVENTTYPE EventAirplaneRequestTakeOff::getTypeEvent() {
   return AIRPLANEREQUESTTAKEOFF;
}

std::string EventAirplaneRequestTakeOff::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Avião " << airplaneName << " está solicitando decolagem";
   return ss.str();
}