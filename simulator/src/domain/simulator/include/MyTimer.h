#pragma once

#include <deque>
#include "Subject.h"
class string;

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

   std::string getDateOnTimestamp(const time_t time);

   static MyTimer* getTimer();
};