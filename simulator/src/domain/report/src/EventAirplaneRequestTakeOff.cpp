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
   ss << "Avi�o " << airplaneName << " est� solicitando decolagem";
   return ss.str();
}