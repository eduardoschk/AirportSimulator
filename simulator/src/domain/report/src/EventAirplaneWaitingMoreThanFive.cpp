#include "EventAirplaneWaitingMoreThanFive.h"

EventAirplaneWaitingMoreThanFive::~EventAirplaneWaitingMoreThanFive() {}

EventAirplaneWaitingMoreThanFive::EventAirplaneWaitingMoreThanFive(long time) : Event(time) {}

EVENTTYPE EventAirplaneWaitingMoreThanFive::getTypeEvent() {
   return EVENTAIRPLANESWAITINGMORETHANFIVE;
}

std::string EventAirplaneWaitingMoreThanFive::getEventToString() {
   return "Existe mais de 5 avi�es aguardando libera��o da pista para pouso";
}