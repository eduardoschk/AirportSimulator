#pragma once

#ifndef WIND_FACTORY_H
#define WIND_FACTORY_H

#include <exception>  
class Wind;

class WindFactory
{
public:
   class DegreeWindException : public std::exception {
      virtual const char* what() const {
         return "Erro ao identificar sentido do vento";
      }
   };   

   ~WindFactory();
   WindFactory();

   Wind* makeWindStatus(const double degreeWind) throw(DegreeWindException);
};

#endif // WIND_FACTORY_H