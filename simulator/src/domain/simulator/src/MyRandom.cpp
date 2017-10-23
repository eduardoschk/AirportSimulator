#include <time.h>
#include <random>
#include <sstream>
#include "MyRandom.h"

std::string generateCompanyName();
std::string generateManufacturers();

long MyRandom::generateRandomValueBetween(int min, int max)
{
   srand( static_cast<unsigned>(time(nullptr)) );
   return rand() % (max - min + 1) + min;
}

///////////////////////////////////////////////////////////////////////////////

std::string MyRandom::generateNameAirplane() 
{
   std::stringstream ss;
   ss << generateCompanyName() << " - " << generateManufacturers() << " " << MyRandom::generateRandomValueBetween(600, 800);
   return ss.str();
}

std::string generateCompanyName()
{
   switch (MyRandom::generateRandomValueBetween(1, 4))
   {
   case 1: return "TAM";
   case 2: return "Gol";
   case 3: return "Azul";
   case 4: return "American Airlines";
   default: return "Particular";
   }
}

std::string generateManufacturers()
{
   switch (MyRandom::generateRandomValueBetween(1, 4))
   {
   case 1: return "Bombardier";
   case 2: return "Airbus";
   case 3: return "Embraer";
   case 4: return "Boing";
   default: return "Particular";
   }
}