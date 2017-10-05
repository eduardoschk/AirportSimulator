#pragma once
#include <string>

class MyRandom 
{
public:
   MyRandom() {}
   ~MyRandom() {}
   static long generateRandomValueBetween(int min, int max);
   static std::string generateNameAirplane();
};