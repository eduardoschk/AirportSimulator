#pragma once

#include <deque>
#include "Subject.h"

class Observer;

class MyTimer :
   public Subject
{
private:
   std::deque<Observer*> observers;

   typedef std::deque<Observer*>::iterator iter;

   static MyTimer* instance;

public:
   MyTimer();
   ~MyTimer();

   long getActualTime();
   long differenceBetweenActualTimeInSeconds(long time);
   void sleep(int seconds);
   void startApp();

   void add(Observer* observer);
   void notifyAll();

   static MyTimer* getTimer();
};