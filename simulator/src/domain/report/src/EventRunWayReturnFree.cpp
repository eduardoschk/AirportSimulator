#include "EventRunWayReturnFree.h"
#include "MyTimer.h"
#include <sstream>

EventRunWayReturnFree::~EventRunWayReturnFree() {}

EventRunWayReturnFree::EventRunWayReturnFree(long time, std::string idRunWay) : Event(time) {
   runWay= idRunWay;
}

EVENTTYPE EventRunWayReturnFree::getTypeEvent() {
   return RUNWAYFREE;
}

std::string EventRunWayReturnFree::getEventToString() {
   std::stringstream ss;
  ss << Event::getEventToString();
   ss << "Pista " << runWay << " retornou a ficar disponivel";
   return ss.str();
}