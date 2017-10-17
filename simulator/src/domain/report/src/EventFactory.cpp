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

EventFactory::~EventFactory() {}

EventFactory::EventFactory() : timer(MyTimer::getTimer()) {}

Event* EventFactory::makeEvent(EVENTTYPE type, void* arg) {
   switch(type) {
   case WINDCHANGE: return makeChangeWindEvent(arg);
   case AIRPLANELANDING: return makeAirplaneLandingEvent(arg);
   case AIRPLANECHANGEAIRPORT: return makeAirplaneChangeAirportEvent(arg);
   case AIRPLANEREQUESTLANDING: return makeAirplaneRequestAirportEvent(arg);
   case AIRPLANEREQUESTTAKEOFF: return makeAirplaneRequestTakeOffEvent(arg);
   case AIRPLANETAKEOFF: return makeAirplaneTakeOffdEvent(arg);
   case RUNWAYFREE: return makeRunWayFreeEvent(arg);
   default: return nullptr;
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

Event* EventFactory::makeAirplaneRequestTakeOffEvent(void* arg) {
   return new EventAirplaneRequestTakeOff(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplaneTakeOffdEvent(void* arg) {
   return nullptr;
}

Event* EventFactory::makeRunWayFreeEvent(void* arg) {
   return new EventRunWayReturnFree(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplaneLandingEvent(void* arg) {
   return nullptr;
}

std::string EventFactory::getStringByArg(void* arg) {
   return *(static_cast<std::string*>(arg));
}
