#include "EventRequestsToTakeOffMoreThanFive.h"

EventRequestsToTakeOffMoreThanFive::~EventRequestsToTakeOffMoreThanFive() {}

EventRequestsToTakeOffMoreThanFive::EventRequestsToTakeOffMoreThanFive(long time) : Event(time) {}

EVENTTYPE EventRequestsToTakeOffMoreThanFive::getTypeEvent() {
   return EVENTREQUESTSTAKEOFFMORETHANFIVE;
}

std::string EventRequestsToTakeOffMoreThanFive::getEventToString() {
   return "Existe mais de 5 requisi��es de decolagem aguardando serem resolvidas";
}