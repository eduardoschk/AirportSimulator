#pragma once

#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;

class Subject
{
public:
   virtual ~Subject() {};
   virtual void add(Observer* observer) = 0;
   virtual void notifyAll() = 0;
};

#endif // SUBJECT_H