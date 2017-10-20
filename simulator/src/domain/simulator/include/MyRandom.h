#pragma once

#ifndef INCLUDED_MY_RANDOM_H
#define INCLUDED_MY_RANDOM_H

#include <string>

class MyRandom 
{
private:
   ~MyRandom() {}
   MyRandom() {}
public:
   static std::string generateNameAirplane();
   static long generateRandomValueBetween(int min, int max);
};

#endif // INCLUDED_MY_RANDOM_H