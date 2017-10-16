#include "MyTimer.h"
#include <time.h>
#include <iostream>
#include "Observer.h"
#include <string>

MyTimer::~MyTimer() {
   observers.clear();
   instance= nullptr;
}


long MyTimer::getActualTime() {
   time_t t;
   return time(&t); 
}

void MyTimer::sleep(const int seconds) {
   time_t start, actualTime;
   time(&start);
   for(time(&actualTime); actualTime < start + seconds; time(&actualTime)) {}
}

void MyTimer::startStopwatch(const long limit) {
   time(&initialTimer);
   time_t timeOut= initialTimer + limit;
   
   for (time_t actualTime= MyTimer::getActualTime() ; actualTime <= timeOut ; sleep(1), time(&actualTime)) {
      std::cout << "---------------" << getDateOnTimestamp(actualTime) << "---------------\n";
      notifyAll();
   }
}

void MyTimer::add(Observer* observer) {
   observers.push_back(observer);
}

void MyTimer::remove(Observer* observer) {
   for (ObserversIterator iterator = observers.begin() ; iterator != observers.end() ; ++iterator) {
      if ((*iterator) == observer) {
         observers.erase(iterator);
         break;
      }
   }
}

void MyTimer::notifyAll() {
   for (ObserversIterator iterator = observers.begin() ; iterator != observers.end() ; ++iterator) {
      (*iterator)->updateTime(MyTimer::getActualTime());
   }
}

std::string MyTimer::getDateOnTimestamp(const time_t time)
{
   time_t aux= initialTimer;
   aux+= (time - initialTimer) * 240;
   struct tm *tm = localtime(&aux);
   char teste[17];
   strftime(teste, 17, "%d/%m/%Y %H:%M", tm);
   return std::string(teste);
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

MyTimer* MyTimer::instance= nullptr;

MyTimer* MyTimer::getTimer() {
   if (!instance)
      instance= new MyTimer();
   return instance;
}