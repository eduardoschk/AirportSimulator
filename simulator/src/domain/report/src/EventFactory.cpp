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

EventFactory::EventFactory() : timer(MyTimer::getTimer()) {}

///////////////////////////////////////////////////////////////////////////////

// Return nullptr if event type are wrong

Event* EventFactory::makeEvent(EVENTTYPE type, void* arg) 
{
   switch(type) 
   {
   case EVENT_WIND_CHANGE:                         return makeChangeWindEvent(arg);
   case EVENT_AIRPLANE_LANDING:                    return makeAirplaneLandingEvent(arg);
   case EVENT_AIRPLANE_CHANGE_AIRPORT:             return makeAirplaneChangeAirportEvent(arg);
   case EVENT_AIRPLANE_REQUEST_LANDING:            return makeAirplaneRequestAirportEvent(arg);
   case EVENT_AIRPLANE_REQUEST_TAKE_OFF:           return makeAirplaneRequestTakeOffEvent(arg);
   case EVENT_AIRPLANE_TAKE_OFF:                   return makeAirplaneTakeOffdEvent(arg);
   case EVENT_RUN_WAY_FREE:                        return makeRunWayFreeEvent(arg);
   case EVENT_AIRPLANES_WAITING_MORE_THAN_FIVE:    return makeAirplanesWaitingMoreThanFive();
   case EVENT_CAPACITY_MORE_THAN_SEVENTY:          return makeCapacityMoreThanSeventy();
   case EVENT_REQUESTS_TAKE_OFF_MORE_THAN_FIVE:    return makeRequestsTakeOffMoreThanFive();
   default:                                        return nullptr;
   }
}

Event* EventFactory::makeChangeWindEvent(void* arg) 
{
   return new EventWindChange(timer->getActualTime(), Direction::toString(((Wind*)arg)->getDirectionWind()));
}

Event* EventFactory::makeAirplaneRequestAirportEvent(void* arg) 
{
   return new EventAirplaneRequestLanding(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplaneChangeAirportEvent(void* arg) 
{
   return new EventAirplaneChangeAirport(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeRequestsTakeOffMoreThanFive() 
{
   return new EventRequestsToTakeOffMoreThanFive(timer->getActualTime());
}

Event* EventFactory::makeAirplaneRequestTakeOffEvent(void* arg) 
{
   return new EventAirplaneRequestTakeOff(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplanesWaitingMoreThanFive() 
{
   return new EventAirplaneWaitingMoreThanFive(timer->getActualTime());
}

Event* EventFactory::makeAirplaneTakeOffdEvent(void* arg) 
{
   return new EventAirplaneTakeOff(timer->getActualTime(), ((Airplane*)arg)->getName(), ((Airplane*)arg)->getCountPassengers());
}

Event* EventFactory::makeRunWayFreeEvent(void* arg) 
{
   return new EventRunWayReturnFree(timer->getActualTime(), getStringByArg(arg));
}

Event* EventFactory::makeAirplaneLandingEvent(void* arg) 
{
   return new EventAirplaneLanding(timer->getActualTime(), ((Airplane*)arg)->getName(), ((Airplane*)arg)->getCountPassengers());
}

Event* EventFactory::makeCapacityMoreThanSeventy() 
{
   return new EventCapacityMoreThanSeventy(timer->getActualTime());
}

///////////////////////////////////////////////////////////////////////////////

std::string EventFactory::getStringByArg(void* arg) 
{
   return *(static_cast<std::string*>(arg));
}
