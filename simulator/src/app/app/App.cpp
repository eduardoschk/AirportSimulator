#include "App.h"
#include "WindController.h"
#include "AirplaneController.h"
#include "MyTimer.h"
#include "TowerOfControl.h"
#include <locale.h>

void App::runApp() {
   setlocale(LC_ALL, "Portuguese");
   
   WindController *wind= new WindController();
   AirplaneController *airplane= new AirplaneController();
   TowerOfControl *tc= TowerOfControl::getInstance();
   tc->setLimitAirplanes(1);
   MyTimer* mt= MyTimer::getTimer();
   mt->startStopwatch(20);

   delete wind;
   delete airplane;
   delete tc;
   delete mt;
}