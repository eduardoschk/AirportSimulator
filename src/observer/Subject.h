#pragma once

class Observer;

class Subject
{
public:
   virtual ~Subject() {};
   virtual void add(Observer* observer) = 0;
   virtual void notifyAll() = 0;
};

