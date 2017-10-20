#pragma once
#ifndef INCLUDED_USERINTERFACE_H
#define INCLUDED_USERINTERFACE_H

#include <string>

enum MENU_OPTIONS {
   MENU_OPT_NUMBER_AIRPLANES_LANDING= 1,
   MENU_OPT_NUMBER_AIRPLANES_ON_GROUND= 2,
   MENU_OPT_AIRPLANES_REQUESTS_AND_TIME_WAITING= 3,
   MENU_OPT_NUMBER_PASSENGERS= 4,
   MENU_OPT_WIND_CHANGE= 5,
   MENU_OPT_CRITICAL_SITUATIONS= 6, 
   MENU_OPT_LOG= 7
};

class UserInterface
{
public:
   ~UserInterface() {}
   UserInterface();

   int getMenuOptionAndShowMenu();
   int requestOption(const std::string& message);

   void showMessage(const std::string& message);
};

#endif // INCLUDED_USERINTERFACE_H