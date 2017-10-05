#include "MyTimer.h"
#include <time.h>
#include <iostream>
#include "Observer.h"

MyTimer* MyTimer::instance= nullptr;

MyTimer::MyTimer() {}

MyTimer::~MyTimer() {}

long MyTimer::getActualTime() 
{
   time_t t;
   return time(&t); 
}

long MyTimer::differenceBetweenActualTimeInSeconds(long time) {
   return (getActualTime() - time);
}

void MyTimer::sleep(int seconds) {
   time_t start, actualTime;
   time(&start);
   for(time(&actualTime); actualTime < start + seconds; time(&actualTime)) {}
}

void MyTimer::startApp() 
{
   time_t initialTimer= time(&initialTimer);
   time_t timeOut= initialTimer + 20;
   for ( time_t actualTime= MyTimer::getActualTime() ; actualTime <= timeOut ; sleep(1)) {
      notifyAll();
   }
}

MyTimer* MyTimer::getTimer() {
   if (!instance)
      instance= new MyTimer();
   return instance;
}

void MyTimer::add(Observer* observer) {
   observers.push_back(observer);
}

void MyTimer::notifyAll() {
   for (iter it = observers.begin() ; it != observers.end() ; ++it) {
      (*it)->updateTime(MyTimer::getActualTime());
   }
}