#include "Log.h"
#include "MyRandom.h"
#include "WindFactory.h"
#include "WindMonitoring.h"

WindMonitoring::WindMonitoring() : windFactory(new WindFactory()), actualWind(nullptr), log(Log::getInstance()) 
{
   directionWindChange(MyRandom::generateRandomValueBetween(0, 36) * 10);
}

WindMonitoring::~WindMonitoring() 
{
   delete windFactory;
   delete actualWind;
   instance= nullptr;
}

///////////////////////////////////////////////////////////////////////////////

void WindMonitoring::directionWindChange(double degree) 
{
   if (actualWind)
      delete actualWind;
   actualWind= windFactory->makeWindStatus(degree);
   log->registryEvent(EVENT_WIND_CHANGE, actualWind);
}

///////////////////////////////////////////////////////////////////////////////

Wind& WindMonitoring::getActualWind() 
{
   return *actualWind;
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

WindMonitoring* WindMonitoring::instance= nullptr;

WindMonitoring* WindMonitoring::getInstance() 
{
   if (!instance)
      instance= new WindMonitoring();
   return instance;
}
