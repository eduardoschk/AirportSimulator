#pragma once

#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airport;

class Airplane
{
private: 
   Airport* airport;
   int timeRequest;
   char* name;

public:
   Airplane(char* _name);
   ~Airplane() {}

   void requestLanding();
   int getTimeFirstRequest() { return timeRequest; }
   void liberadoPistaParaDecolar();
   void liberadoPistaParaPousar();
};

#endif