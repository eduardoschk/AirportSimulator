#pragma once

#include <string>

class Airport;

class Airplane 
{
private:
   std::string name;
   Airport* airport;
   long landingTime;

public:
   Airplane(std::string _name);
   ~Airplane();

   std::string getName();

   void requestLandingToAirport();

   void landingStripFree();
};