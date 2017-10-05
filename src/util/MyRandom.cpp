#include <time.h>
#include <random>
#include <sstream>
#include "MyRandom.h"

long MyRandom::generateRandomValueBetween(int min, int max)
{
   srand(time(NULL));
   return rand()%(max-min + 1) + min;
}

std::string MyRandom::generateNameAirplane() {
   std::stringstream ss;
   if (MyRandom::generateRandomValueBetween(1, 2) == 1) {
      ss << "Boing ";
   } else {
      ss << "Airbus ";
   }
   ss << MyRandom::generateRandomValueBetween(600, 800);
   return ss.str();
}