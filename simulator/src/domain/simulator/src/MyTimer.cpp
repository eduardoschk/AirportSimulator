#include <time.h>
#include <string>
#include <iostream>
#include "MyTimer.h"
#include "Observer.h"
#include "Log.h"


MyTimer::~MyTimer() 
{
   observers.clear();
   instance= nullptr;
}

long MyTimer::getActualTime() 
{
   time_t t;
   return static_cast<long>(time(&t)); 
}

void MyTimer::sleep(const int seconds) 
{
   time_t start, actualTime;
   time(&start);
   for( time(&actualTime) ; actualTime < start + seconds ; time(&actualTime) ) {}
}

void MyTimer::startStopwatch() 
{
   time(&initialTimer);
   time_t timeOut= initialTimer + timeForStopwatching;
   
   for (time_t actualTime= MyTimer::getActualTime() ; actualTime <= timeOut ; sleep(1), time(&actualTime))
      notifyAll();
}

///////////////////////////////////////////////////////////////////////////////

void MyTimer::addObserver(Observer* observer) 
{
   observers.push_back(observer);
}

void MyTimer::removeObserver(Observer* observer) 
{
   for (ObserversIterator iterator = observers.begin() ; iterator != observers.end() ; ++iterator) 
   {
      if ((*iterator) == observer) 
      {
         observers.erase(iterator);
         break;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////

void MyTimer::notifyAll() 
{
   for (ObserversIterator iterator = observers.begin() ; iterator != observers.end() ; ++iterator)
      (*iterator)->updateTime(MyTimer::getActualTime());
}

///////////////////////////////////////////////////////////////////////////////

void MyTimer::setTimeLimit(long limit) 
{
   timeForStopwatching= limit;
}

long MyTimer::getTimeLimit() 
{
   return timeForStopwatching;
}

time_t MyTimer::getInitialTimer() 
{
   return initialTimer;
}

std::string MyTimer::getDateOnTimestamp(const time_t time) 
{
   time_t initialTimer;
   struct tm tm;

   if (instance->getInitialTimer() > 0) 
      initialTimer= instance->getInitialTimer();
   else 
      initialTimer= getActualTime();

   time_t auxTimer = initialTimer;

   auxTimer+= (time - initialTimer) * 240;
   localtime_s(&tm, &auxTimer);
   char buffer[17];
   strftime(buffer, 17, "%d/%m/%Y %H:%M", &tm);

   return std::string(buffer);
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

MyTimer* MyTimer::instance= nullptr;

MyTimer* MyTimer::getTimer() 
{
   if (!instance)
      instance= new MyTimer();
   return instance;
}