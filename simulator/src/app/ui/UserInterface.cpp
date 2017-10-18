#include "UserInterface.h"
#include <iostream>

int UserInterface::requestOption(const std::string& message) {
   int option;
   std::cout << message << std::endl;
   std::cin >> option;
   return option;
}

void UserInterface::showMessage(const std::string& message) {
   std::cout << message << std::endl;
}
