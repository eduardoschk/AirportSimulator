#include "WindMonitoring.h"
#include "WindFactory.h"
#include "MyRandom.h"
#include "MyTimer.h"
#include <iostream>

WindMonitoring* WindMonitoring::instance= 0;

WindMonitoring::WindMonitoring() : windFactory(new WindFactory()), timeChangeOcurred(-1) {
   directionWindChange(MyRandom::generateRandomValueBetween(0, 360));
   calculateNextTimeWindChange();
   timer= MyTimer::getTimer();
}

void WindMonitoring::directionWindChange(double degree)
{
   timeChangeOcurred= timer->getActualTime();
   actualWind= windFactory->makeWindStatus(degree);
}

Wind* WindMonitoring::getActualWind() 
{
   return actualWind;
}

long WindMonitoring::getTimeChageOcurred() {
   return timeChangeOcurred;
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

void WindMonitoring::updateTime(long time) {
   if (time == timeNextChange) {
      std::cout << "Alterando Vento" << std::endl;
      std::cout << "Vento Atual: " << Direction::toString(actualWind->getDirectionWind()) << std::endl;
      directionWindChange( MyRandom::generateRandomValueBetween(0, 360) );
      std::cout << "Novo Vento: " << Direction::toString(actualWind->getDirectionWind()) << std::endl;
      calculateNextTimeWindChange();
   }
}

void WindMonitoring::calculateNextTimeWindChange() {
   timeNextChange= timer->getActualTime() + MyRandom::generateRandomValueBetween(4, 10);
}