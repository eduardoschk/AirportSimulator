#include "WindController.h"
#include "WindMonitoring.h"
#include "MyTimer.h"
#include "MyRandom.h"

//Para testes
#include <iostream>
#include "Direction.h"

WindController::WindController() : timer(MyTimer::getTimer()), windMonitoring(WindMonitoring::getInstance()) {
   calculateTimeWindChange();
   timer->add(this);
}

WindController::~WindController() {
   delete windMonitoring;
   timer->remove(this);
}


void WindController::changeWind() {
   windMonitoring->directionWindChange( MyRandom::generateRandomValueBetween(0, 36) * 10 );
   std::cout << "Vento alterado para - " << Direction::toString(windMonitoring->getActualWind()->getDirectionWind()) << "\n\n"; 
   calculateTimeWindChange();
}

void WindController::updateTime(const long time) {
   if (time >= timeToChangeWind) {
      changeWind();
   }
}

void WindController::calculateTimeWindChange() {
   timeToChangeWind= timer->getActualTime() + MyRandom::generateRandomValueBetween(4, 10);
}
