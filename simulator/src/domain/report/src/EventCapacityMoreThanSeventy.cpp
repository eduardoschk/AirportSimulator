#include "EventCapacityMoreThanSeventy.h"

EventCapacityMoreThanSeventy::EventCapacityMoreThanSeventy(long time) : Event(time) {}

EventCapacityMoreThanSeventy::~EventCapacityMoreThanSeventy(void) {}

EVENTTYPE EventCapacityMoreThanSeventy::getTypeEvent() {
   return EVENTCAPACITYMORETHANSEVENTY;
}

std::string EventCapacityMoreThanSeventy::getEventToString() {
   return "Capacidade de avi�es em solo do aeroporto atingida";
}