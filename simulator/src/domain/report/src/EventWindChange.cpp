#include "EventWindChange.h"
#include <sstream>
#include "MyTimer.h"

EventWindChange::~EventWindChange() {}

EventWindChange::EventWindChange(long time, Direction::DIRECTIONS newDirection) : Event(time) {
   direction= newDirection;
}

EVENTTYPE EventWindChange::getTypeEvent() {
   return EVENTWINDCHANGE;
}

std::string EventWindChange::getEventToString() {
   std::stringstream ss;
   ss << Event::getEventToString();
   ss << "Vento alterado para " << Direction::toString(direction) << "\n";
   return ss.str();
}