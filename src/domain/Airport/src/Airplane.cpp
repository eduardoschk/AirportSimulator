#include "Airplane.h"
#include "Airport.h"
#include <iostream>

Airplane::Airplane(char* _name) : name(_name), airport(Airport::getInstance()), timeRequest(-1)  {}

void Airplane::requestLanding() {
   std::cout << "Aviao pediu para pousar" << std::endl;
   if (timeRequest < 0)
      timeRequest= 1;
   airport->requisitaPistaParaPousar(*this);
}

void Airplane::liberadoPistaParaDecolar() {
   std::cout << "Aviao Liberado para decolar" << std::endl;
}

void Airplane::liberadoPistaParaPousar() {
   std::cout << "Aviao Liberado para pouso" << std::endl;
}