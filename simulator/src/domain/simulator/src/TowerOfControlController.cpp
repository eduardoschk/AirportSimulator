#include "TowerOfControlController.h"
#include "TowerOfControl.h"
#include "MyTimer.h"

TowerOfControlController::~TowerOfControlController() {
   timer->remove(this);
   delete towerOfControl;
}

TowerOfControlController::TowerOfControlController() : timer(MyTimer::getTimer()), towerOfControl(TowerOfControl::getInstance()) {
   timer->add(this);
}

void TowerOfControlController::setLimitAirplanes(int limit) {
   towerOfControl->setLimitAirplanes(limit);      
}

void TowerOfControlController::updateTime(const long time) {
   towerOfControl->verifyRequests();
}