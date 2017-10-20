#pragma once
#ifndef INCLUDED_CONTROLLER_TOWER_OF_CONTROL_H
#define INCLUDED_CONTROLLER_TOWER_OF_CONTROL_H

#include "Observer.h"

class TowerOfControl;
class MyTimer;

class TowerOfControlController :
   public Observer
{
private:
   MyTimer* timer;
   TowerOfControl* towerOfControl;

public:
   ~TowerOfControlController();
   TowerOfControlController();

   void setLimitAirplanes(int limit);

   void updateTime(const long time);
};

#endif // INCLUDED_CONTROLLER_TOWER_OF_CONTROL_H