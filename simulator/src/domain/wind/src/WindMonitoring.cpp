#include "WindMonitoring.h"
#include "WindFactory.h"
#include "MyRandom.h"
#include "MyTimer.h"
#include "Log.h"

//para testes
#include <iostream>

WindMonitoring::WindMonitoring() : windFactory(new WindFactory()), actualWind(nullptr), log(Log::getInstance()) {
   directionWindChange(MyRandom::generateRandomValueBetween(0, 36) * 10);
}

WindMonitoring::~WindMonitoring() {
   delete windFactory;
   delete actualWind;
   instance= nullptr;
}

void WindMonitoring::directionWindChange(double degree) {
   if (actualWind)
      delete actualWind;
   actualWind= windFactory->makeWindStatus(degree);
   log->registryEvent(EVENTWINDCHANGE, actualWind);
}

Wind* WindMonitoring::getActualWind() {
   return actualWind;
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

WindMonitoring* WindMonitoring::instance= nullptr;

WindMonitoring* WindMonitoring::getInstance() {
   if (!instance)
      instance= new WindMonitoring();
   return instance;
}
