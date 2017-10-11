#include "WindFactory.h"
#include "Wind.h"

WindFactory::WindFactory() {}

WindFactory::~WindFactory() {}

Wind* WindFactory::makeWindStatus(const double degreeWind) 
{
   if (degreeWind < 0 || degreeWind > 360) 
      throw DegreeWindException();

   if (degreeWind >= 337.5 && degreeWind <= 360 || degreeWind <=22.5) 
      return new NorthWind();

   if (degreeWind > 292.5 && degreeWind < 337.5) 
      return new NorthwestWind();

   if (degreeWind >= 247.5 && degreeWind <= 292.5) 
      return new WestWind();

   if (degreeWind > 202.5 && degreeWind < 247.5) 
      return new SouthwestWind();

   if (degreeWind >= 157.5 && degreeWind <= 202.5) 
      return new SouthWind();

   if (degreeWind > 112.5 && degreeWind < 157.5) 
      return new SoutheastWind();

   if (degreeWind >= 67.5 && degreeWind <= 112.5) 
      return new EastWind();

   if (degreeWind > 22.5 && degreeWind < 67.5) 
      return new NortheastWind();
   
   throw DegreeWindException();
}