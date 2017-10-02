#include "WindMonitoring.h"
#include "WindFactory.h"

WindMonitoring* WindMonitoring::instance= 0;

WindMonitoring::WindMonitoring() : windFactory(new WindFactory()) {
   directionWindChange(350);
}

void WindMonitoring::directionWindChange(double degree)
{
   actualWind= windFactory->makeWindStatus(degree);
}

Wind* WindMonitoring::getActualWind() 
{
   return actualWind;
}

WindMonitoring* WindMonitoring::getInstance() {
   if (!instance)
      instance= new WindMonitoring();
   return instance;
}

void WindMonitoring::resetInstance() {
   if (instance)
      delete instance;
   instance= nullptr;
}