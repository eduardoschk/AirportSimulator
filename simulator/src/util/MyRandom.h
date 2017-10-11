#pragma once
#include <string>

class MyRandom 
{
private:
   ~MyRandom() {}
   MyRandom() {}
public:
   static long generateRandomValueBetween(const int min, const int max);
   static std::string generateNameAirplane();
};