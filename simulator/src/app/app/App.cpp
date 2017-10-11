#include "App.h"
#include "WindController.h"
#include "AirplaneController.h"
#include "Airport.h"
#include "MyTimer.h"
#include "TowerOfControl.h"

void App::runApp() {
   WindController wind;
   AirplaneController airplane;
   Airport::getInstance();
   TowerOfControl *tc= TowerOfControl::getInstance();
   tc->setLimitAirplanes(5);
   MyTimer* mt= MyTimer::getTimer();
   mt->startStopwatch();
   delete tc;
   delete mt;
}