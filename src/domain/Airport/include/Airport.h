#pragma once

#ifndef AIRPORT_H
#define AIRPORT_H

#include <exception>
#include <queue>
#include "WindMonitoring.h"
#include "Direction.h"
#include "RunWay.h"
#include "Requisicao.h"

class Airplane;

class Airport 
{
private: 
   int limitOfAirplanesInLanding;
   WindMonitoring* windMonitoring;
   RunWay* runWays[3];
   std::queue<Requisicao> filaRequisicoes;

   RunWay* getRunWayAvaible();

protected:
   Airport();
   ~Airport() {}

public:
   static Airport* getInstance();
   static void resetInstance();

   class ClosedAirport : public std::exception { virtual const char* what() const { return "Aeroporto fechado"; } };
   class NoRunWaysAvaible : public std::exception { virtual const char* what() const { return "Sem pista de pouso liberada"; } };

   int getLimitOfAirplanesInLanding();
   void requisitaPistaParaPousar(Airplane& air);
   void setLimitOfAirplanesInLanding(int limit) { limitOfAirplanesInLanding= limit; }
   bool runWaysIsAvaible(RunWay* runWay);
   bool isOpenToUsingLanding();
   bool existsRunWayAvaible();
   void tratarRequisicoes();

};

#endif