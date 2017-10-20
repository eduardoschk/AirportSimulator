#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

class MyTimer;
class WindController;
class ReportController;
class AirplaneController;
class TowerOfControlController;

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

   MyTimer& getTimer();
   WindController& getWindController();
   ReportController& getReportController();
   AirplaneController& getAirplaneController();
   TowerOfControlController& getControllerTowerOfControl();

};

#endif //INCLUDED_DATA_H