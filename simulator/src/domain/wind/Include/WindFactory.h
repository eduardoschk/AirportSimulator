#pragma once

#ifndef INCLUDED_WIND_FACTORY_H
#define INCLUDED_WIND_FACTORY_H

class Wind;

class WindFactory
{
public:
   ~WindFactory() {}
   WindFactory() {}

   Wind* makeWindStatus(const double degreeWind);
};

#endif // INCLUDED_WIND_FACTORY_H