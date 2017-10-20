#include <Windows.h>
#include "App.h"
#include "MyData.h"
#include "CmdLog.h"
#include "MyTimer.h"
#include "UserInterface.h"
#include "CmdReportPassengers.h"
#include "CmdReportWindChange.h"
#include "TowerOfControlController.h"
#include "CmdReportAirplanesLanding.h"
#include "CmdReportAirplanesOnGround.h"
#include "CmdReportCriticalSituations.h"
#include "CmdReportAirplanesRequestsAndTimeWaiting.h"

HANDLE thread;

App::~App() 
{
   delete data;
   delete ui;
   DWORD result= TerminateThread(thread, 1);
   cleanCurrentCmd();
}

App::App()
{
   data= new MyData();
   currentCmd= nullptr;
   ui= new UserInterface();
}

DWORD WINAPI threadFunction( LPVOID lpParam ) 
{
   ((MyTimer*)lpParam)->startStopwatch();
   return 0;
}

///////////////////////////////////////////////////////////////////////////////

void App::run() 
{
   initAirport();
   thread= CreateThread(nullptr, 0, threadFunction, &(data->getTimer()), NULL, nullptr);
   runApp();
}

///////////////////////////////////////////////////////////////////////////////

void App::runApp()
{
   while (true) 
   {
      if (!createCmd(ui->getMenuOptionAndShowMenu()))
         break;
   }
}

void App::initAirport()
{
   data->getTimer().setTimeLimit( ui->requestOption("Quantos segundos durará a simulação?") );
   data->getControllerTowerOfControl().setLimitAirplanes( ui->requestOption("Quantos aviões poderão pousar?") );
}

///////////////////////////////////////////////////////////////////////////////

void App::cleanCurrentCmd() 
{
   if (currentCmd)
      delete currentCmd;
   currentCmd= nullptr;
}

bool App::createCmd(int menuOption) 
{
   cleanCurrentCmd();

   switch (menuOption) 
   {
   case MENU_OPT_NUMBER_AIRPLANES_LANDING:            currentCmd= new CmdReportAirplanesLanding();                break;
   case MENU_OPT_NUMBER_AIRPLANES_ON_GROUND:          currentCmd= new CmdReportAirplanesOnGround();               break;
   case MENU_OPT_AIRPLANES_REQUESTS_AND_TIME_WAITING: currentCmd= new CmdReportAirplanesRequestsAndTimeWaiting(); break;
   case MENU_OPT_NUMBER_PASSENGERS:                   currentCmd= new CmdReportPassengers();                      break;
   case MENU_OPT_WIND_CHANGE:                         currentCmd= new CmdReportWindChange();                      break;
   case MENU_OPT_CRITICAL_SITUATIONS:                 currentCmd= new CmdReportCriticalSituations();              break;
   case MENU_OPT_LOG:                                 currentCmd= new CmdLog();                                   break;
   }

   return executeCmd();
}

bool App::executeCmd() 
{
   if (currentCmd) 
   {
      currentCmd->execute(*data,*ui);
      return true;
   }
   return false;
}