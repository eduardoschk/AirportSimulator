#include <sstream>
#include "Event.h"
#include "MyTimer.h"

std::string Event::getEventToString()
{
   std::stringstream ss;
   ss << "-- Hora: "<< MyTimer::getDateOnTimestamp(timeEvent) << " -------- ";
   return ss.str();
}
