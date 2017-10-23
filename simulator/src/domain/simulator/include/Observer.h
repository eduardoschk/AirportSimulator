#pragma once

#ifndef INCLUDED_OBSERVER_H
#define INCLUDED_OBSERVER_H

class Observer {
public:
   virtual void updateTime(const long time) = 0;
};

#endif // INCLUDED_OBSERVER_H