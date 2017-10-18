#include <locale.h>
#include <windows.h>
#include "App.h"
#include "MyData.h"
#include "UserInterface.h"
#include "TesteReport.h"
#include "CommandRunAirport.h"

App::App() {
   data= new MyData();
   ui= new UserInterface();
   currentCmd= nullptr;

   setlocale(LC_ALL, "Portuguese");
}

DWORD WINAPI threadFunction( LPVOID lpParam ) {
   App* app= (App*)lpParam;
   app->runAirport();
   return 0;
}

void App::run() {
   runApp();
}

void App::runApp() {
   int i= 1;
   Sleep(3000);
   while (i != 0) {
      Sleep(1000);
      TesteReport report;
      report.execute(*data, *ui);
   }
}

void App::runAirport() {
   CommandRunAirport command;
   command.execute(*data, *ui);
}