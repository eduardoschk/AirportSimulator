#pragma once

#ifndef INCLUDED_SUBJECT_H
#define INCLUDED_SUBJECT_H

class Observer;

class Subject
{
public:
   virtual void notifyAll() = 0;

   virtual void addObserver(Observer* observer) = 0;
   virtual void removeObserver(Observer* observer) = 0;
};

#endif // INCLUDED_SUBJECT_H