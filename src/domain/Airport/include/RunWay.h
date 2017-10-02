#pragma once

#ifndef RUNWAY_H
#define RUNWAY_H

#include "Direction.h"

class RunWay
{
private:
   Direction::DIRECTIONS directionRunWay;
   bool landingAvaible;
public:
   ~RunWay() {}
   RunWay(Direction::DIRECTIONS _directionRunWay);

   bool isAvaible() { return landingAvaible; }
   Direction::DIRECTIONS getDirectionRunWay() { return directionRunWay; }
   void runwayInUse();

protected:
   void outroTeste();
};

#endif