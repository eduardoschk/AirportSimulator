#pragma once

#ifndef INCLUDED_MY_TIMER_H
#define INCLUDED_MY_TIMER_H

#include <deque>
#include "Subject.h"

class Observer;

class MyTimer :
   public Subject
{
private:
   time_t initialTimer;
   long timeForStopwatching;
   std::deque<Observer*> observers;

   typedef std::deque<Observer*>::iterator ObserversIterator;

   static MyTimer* instance;

   void notifyAll();
   void notifyEnd();

   MyTimer() {}

public:
   ~MyTimer();

   static long getActualTime();
   static void sleep(const int seconds);

   void startStopwatch();

   
   void addObserver(Observer* observer);
   void removeObserver(Observer* observer);

   long getTimeLimit();
   void setTimeLimit(const long limit);

   time_t getInitialTimer();

   static std::string getDateOnTimestamp(const time_t time);

   static MyTimer* getTimer();
};

#endif // INCLUDED_MY_TIMER_H