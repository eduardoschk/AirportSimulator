#include <sstream>
#include "MyTimer.h"
#include "EventRunWayReturnFree.h"

EventRunWayReturnFree::EventRunWayReturnFree(long time, std::string idRunWay) : Event(time) 
{
   runWay= idRunWay;
}

///////////////////////////////////////////////////////////////////////////////

EVENTTYPE EventRunWayReturnFree::getTypeEvent() 
{
   return EVENT_RUN_WAY_FREE;
}

std::string EventRunWayReturnFree::getEventToString() 
{
   std::stringstream ss;
   ss << Event::getEventToString()
      << "Pista " << runWay << " retornou a ficar disponivel \n";
   return ss.str();
}