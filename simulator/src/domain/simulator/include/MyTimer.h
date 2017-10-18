#pragma once

#ifndef MY_TIMER_H
#define MY_TIMER_H

#include <deque>
#include "Subject.h"

class Observer;

class MyTimer :
   public Subject
{
private:
   std::deque<Observer*> observers;
   time_t initialTimer;

   typedef std::deque<Observer*>::iterator ObserversIterator;

   static MyTimer* instance;

   MyTimer() {}

public:
   ~MyTimer();

   static long getActualTime();
   static void sleep(const int seconds);
   void startStopwatch(const long limit);

   void add(Observer* observer);
   void remove(Observer* observer);
   void notifyAll();

   time_t getInitialTimer();

   static std::string getDateOnTimestamp(const time_t time);

   static MyTimer* getTimer();
};

#endif // MY_TIMER_H