#include "App.h"
#include "WindController.h"
#include "AirplaneController.h"
#include "MyTimer.h"
#include "TowerOfControl.h"

void App::runApp() {
   WindController *wind= new WindController();
   AirplaneController *airplane= new AirplaneController();
   TowerOfControl *tc= TowerOfControl::getInstance();
   tc->setLimitAirplanes(5);
   MyTimer* mt= MyTimer::getTimer();
   mt->startStopwatch(20);

   delete wind;
   delete airplane;
   delete tc;
   delete mt;
}