#pragma once

#ifndef MY_RANDOM_H
#define MY_RANDOM_H

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

#endif //MY_RANDOM_H