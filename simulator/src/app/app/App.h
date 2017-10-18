#pragma once
#ifndef APP_H
#define APP_H

#include "TowerOfControl.h"

class UserInterface;
class MyData;
class Command;

class App
{
private:
   MyData* data;
   UserInterface* ui;
   Command* currentCmd;

public:
   ~App() {}
   App();

   void run();
   void runApp();
   void runAirport();
};

#endif // APP_H