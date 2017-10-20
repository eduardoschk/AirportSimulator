#include "MyData.h"

#include "MyTimer.h"
#include "WindController.h"
#include "ReportController.h"
#include "AirplaneController.h"
#include "TowerOfControlController.h"

MyData::~MyData() {
   delete reportController;
   delete controllerTowerOfControl;
   delete windController;
   delete airplaneController;
   delete timer;
}

MyData::MyData() : timer(MyTimer::getTimer()), controllerTowerOfControl(new TowerOfControlController()), windController(new WindController()), airplaneController(new AirplaneController()), reportController(new ReportController()) {}

///////////////////////////////////////////////////////////////////////////////

MyTimer& MyData::getTimer() 
{
   return *timer;
}

WindController& MyData::getWindController() 
{
   return *windController;
}

ReportController& MyData::getReportController() 
{
   return *reportController;
}

AirplaneController& MyData::getAirplaneController() 
{
   return *airplaneController;
}

TowerOfControlController& MyData::getControllerTowerOfControl() 
{
   return *controllerTowerOfControl;
}
