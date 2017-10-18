#pragma once

#ifndef DATA_H
#define DATA_H

#include "TowerOfControlController.h"
#include "MyTimer.h"
#include "ReportController.h"

class AirplaneController;
class WindController;

class MyData {
private:
   MyTimer* timer;
   WindController* windController;
   ReportController* reportController;
   AirplaneController* airplaneController;
   TowerOfControlController* controllerTowerOfControl;

public:
   ~MyData();
   MyData();

   MyTimer* getTimer();
   WindController* getWindController();
   ReportController* getReportController();
   AirplaneController* getAirplaneController();
   TowerOfControlController* getControllerTowerOfControl();

};

#endif //DATA_H