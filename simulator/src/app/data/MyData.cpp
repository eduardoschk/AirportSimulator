#include "MyData.h"

#include "WindController.h"
#include "AirplaneController.h"

MyData::~MyData() {
   delete controllerTowerOfControl;
   delete windController;
   delete airplaneController;
   delete timer;
}

MyData::MyData() : timer(MyTimer::getTimer()), controllerTowerOfControl(new TowerOfControlController()), windController(new WindController()), airplaneController(new AirplaneController()) {}


MyTimer* MyData::getTimer() {
   return timer;
}

WindController* MyData::getWindController() {
   return windController;
}

ReportController* MyData::getReportController() {
   return reportController;
}

AirplaneController* MyData::getAirplaneController() {
   return airplaneController;
}

TowerOfControlController* MyData::getControllerTowerOfControl() {
   return controllerTowerOfControl;
}
