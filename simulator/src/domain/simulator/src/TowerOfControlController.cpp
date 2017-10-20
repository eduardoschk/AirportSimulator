#include "MyTimer.h"
#include "TowerOfControl.h"
#include "TowerOfControlController.h"

TowerOfControlController::~TowerOfControlController() 
{
   timer->removeObserver(this);
   delete towerOfControl;
}

TowerOfControlController::TowerOfControlController() : timer(MyTimer::getTimer()), towerOfControl(TowerOfControl::getInstance()) 
{
   timer->addObserver(this);
}

///////////////////////////////////////////////////////////////////////////////

void TowerOfControlController::setLimitAirplanes(int limit) 
{
   towerOfControl->setLimitAirplanes(limit);      
}

///////////////////////////////////////////////////////////////////////////////

void TowerOfControlController::updateTime(const long time) 
{
   towerOfControl->verifyAllRequests();
}