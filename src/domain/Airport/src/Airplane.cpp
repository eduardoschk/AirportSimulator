#include "Airplane.h"
#include "Airport.h"
#include <iostream>

Airplane::Airplane(std::string _name) : name(_name), airport(Airport::getInstance()) {}

Airplane::~Airplane() {}

std::string Airplane::getName() {
   return name;
}

void Airplane::requestLandingToAirport() {
   std::cout << "Solicitando aeroporto" << std::endl;
   airport->requestUseAirport(this);
}