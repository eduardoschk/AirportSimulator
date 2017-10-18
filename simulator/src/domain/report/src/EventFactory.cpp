#include "EventFactory.h"
#include "EventAirplaneChangeAirport.h"
#include "EventAirplaneLanding.h"
#include "EventAirplaneRequestLanding.h"
#include "EventAirplaneRequestTakeOff.h"
#include "EventAirplaneTakeOff.h"
#include "EventRunWayReturnFree.h"
#include "EventWindChange.h"
#include "Wind.h"
#include "Airplane.h"
#include "MyTimer.h"
#include "EventRequestsToTakeOffMoreThanFive.h"
#include "EventCapacityMoreThanSeventy.h"
#include "EventAirplaneWaitingMoreThanFive.h"

EventFactory::~EventFactory() {}

EventFactory::EventFactory() : timer(MyTimer::getTimer()) {}

Event* EventFactory::makeEvent(EVENTTYPE type, void* arg) {
   switch(type) {
   case EVENTWINDCHANGE:                     return makeChangeWindEvent(arg);
   case EVENTAIRPLANELANDING:                return makeAirplaneLandingEvent(arg);
   case EVENTAIRPLANECHANGEAIRPORT:          return makeAirplaneChangeAirportEvent(arg);
   case EVENTAIRPLANEREQUESTLANDING:         return makeAirplaneRequestAirportEvent(arg);
   case EVENTAIRPLANEREQUESTTAKEOFF:         return makeAirplaneRequestTakeOffEvent(arg);
   case EVENTAIRPLANETAKEOFF:                return makeAirplaneTakeOffdEvent(arg);
   case EVENTRUNWAYFREE:                     return makeRunWayFreeEvent(arg);
   case EVENTAIRPLANESWAITINGMORETHANFIVE:   return makeAirplanesWaitingMoreThanFive();
   case EVENTCAPACITYMORETHANSEVENTY:        return makeCapacityMoreThanSeventy();
   case EVENTREQUESTSTAKEOFFMORETHANFIVE:    return makeRequestsTakeOffMoreThanFive();
   default:                                  throw EventCreateError();
   }
}

Event* EventFactory::makeChangeWindEvent(void* arg) {
   return new EventWindChange(timer->getActualTime(), ((Wind*)arg)->getDirectionWind());
}

Event* EventFactory::makeAirplaneRequestAirportEvent(void* arg) {
   return new EventAirplaneRequestLanding(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplaneChangeAirportEvent(void* arg) {
   return new EventAirplaneChangeAirport(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeRequestsTakeOffMoreThanFive() {
   return new EventRequestsToTakeOffMoreThanFive(timer->getActualTime());
}

Event* EventFactory::makeAirplaneRequestTakeOffEvent(void* arg) {
   return new EventAirplaneRequestTakeOff(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplanesWaitingMoreThanFive() {
   return new EventAirplaneWaitingMoreThanFive(timer->getActualTime());
}

Event* EventFactory::makeAirplaneTakeOffdEvent(void* arg) {
   return new EventAirplaneTakeOff(timer->getActualTime(), ((Airplane*)arg)->getName(), ((Airplane*)arg)->getCountPassengers());
}

Event* EventFactory::makeRunWayFreeEvent(void* arg) {
   return new EventRunWayReturnFree(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplaneLandingEvent(void* arg) {
   return new EventAirplaneLanding(timer->getActualTime(), ((Airplane*)arg)->getName(), ((Airplane*)arg)->getCountPassengers());
}

Event* EventFactory::makeCapacityMoreThanSeventy() {
   return new EventCapacityMoreThanSeventy(timer->getActualTime());
}

std::string EventFactory::getStringByArg(void* arg) {
   return *(static_cast<std::string*>(arg));
}
