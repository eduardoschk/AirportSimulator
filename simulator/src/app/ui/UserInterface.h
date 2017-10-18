#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>

class UserInterface
{
public:
   ~UserInterface() {}
   UserInterface() {}

   int requestOption(const std::string& message);
   void showMessage(const std::string& message);
};

#endif // USERINTERFACE_H