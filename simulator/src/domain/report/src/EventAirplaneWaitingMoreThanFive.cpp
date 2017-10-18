#include "EventAirplaneWaitingMoreThanFive.h"

EventAirplaneWaitingMoreThanFive::~EventAirplaneWaitingMoreThanFive() {}

EventAirplaneWaitingMoreThanFive::EventAirplaneWaitingMoreThanFive(long time) : Event(time) {}

EVENTTYPE EventAirplaneWaitingMoreThanFive::getTypeEvent() {
   return EVENTAIRPLANESWAITINGMORETHANFIVE;
}

std::string EventAirplaneWaitingMoreThanFive::getEventToString() {
   return "Existe mais de 5 aviões aguardando liberação da pista para pouso";
}