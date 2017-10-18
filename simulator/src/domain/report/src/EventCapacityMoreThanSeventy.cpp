#include "EventCapacityMoreThanSeventy.h"

EventCapacityMoreThanSeventy::EventCapacityMoreThanSeventy(long time) : Event(time) {}

EventCapacityMoreThanSeventy::~EventCapacityMoreThanSeventy(void) {}

EVENTTYPE EventCapacityMoreThanSeventy::getTypeEvent() {
   return EVENTCAPACITYMORETHANSEVENTY;
}

std::string EventCapacityMoreThanSeventy::getEventToString() {
   return "Capacidade de aviões em solo do aeroporto atingida";
}