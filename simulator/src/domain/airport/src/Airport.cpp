#include "Airport.h"
#include "Airplane.h"
#include "RunWay.h"
#include "Direction.h"
#include "WindMonitoring.h"

Airport::Airport() : windMonitoring(WindMonitoring::getInstance()) 
{
   runWays[0]= new RunWay(Direction::SOUTH);
   runWays[1]= new RunWay(Direction::WEST);
   runWays[2]= new RunWay(Direction::SOUTHWEST);
}

Airport::~Airport() 
{
   for (int i= 0 ; i < 3 ; ++i) 
      delete runWays[i];
   instance= nullptr;
}

///////////////////////////////////////////////////////////////////////////////

bool Airport::airportIsAcessible() 
{
   if (getRunWayAvailable())
      return true;
   return false;
}

bool Airport::requestUseAirport(Airplane*) 
{
   RunWay* runWay= getRunWayAvailable();
   if (runWay) 
   {
      runWay->runwaySetToUse();
      return true;
   }
   return false;
}

///////////////////////////////////////////////////////////////////////////////

// Returns a nullptr if don't have an runway available
RunWay* Airport::getRunWayAvailable() 
{
   for (int i= 0 ; i < 3 ; ++i ) 
   {
      if (runWaysIsAvaible(runWays[i]))
         return runWays[i];
   }
   return nullptr;
}

bool Airport::runWaysIsAvaible(RunWay* runWay) {
   if (runWay->isAvailable()) 
   {
      if (! Direction::areTransversesDirections(windMonitoring->getActualWind().getDirectionWind(), runWay->getDirectionRunWay())) 
         return true;
   }
   return false;
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Airport* Airport::instance = nullptr;

Airport* Airport::getInstance() 
{
   if (!instance)
      instance= new Airport();
   return instance;
}