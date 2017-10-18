#pragma once

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
   virtual void updateTime(long time) = 0;
};

#endif // OBSERVER_H