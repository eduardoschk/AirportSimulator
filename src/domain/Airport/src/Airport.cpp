#include "Airport.h"
#include "Airplane.h"

static Airport* instance = nullptr;

Airport::Airport() : limitOfAirplanesInLanding(0), windMonitoring(WindMonitoring::getInstance())
{
   runWays[0]= new RunWay(Direction::SOUTH);
   runWays[1]= new RunWay(Direction::WEST);
   runWays[2]= new RunWay(Direction::SOUTHEAST);
}

void Airport::requisitaPistaParaPousar(Airplane& air) {
   try {
      if (isOpenToUsingLanding()) {
         filaRequisicoes.push(Requisicao(&air, Requisicao::POUSO));
         if (existsRunWayAvaible())
            tratarRequisicoes();
      } else 
         throw ClosedAirport();
   } catch (NoRunWaysAvaible) {
   }
}

void Airport::tratarRequisicoes() {
   if ( !filaRequisicoes.empty() ) {
      Requisicao req= filaRequisicoes.front();
      filaRequisicoes.pop();
      RunWay* runWay= getRunWayAvaible();
      runWay->runwayInUse();
      switch (req.getTypeRequest() ) {
      case Requisicao::POUSO:
         req.getAirplane()->liberadoPistaParaPousar();
         break;
      case Requisicao::DECOLAR:
         req.getAirplane()->liberadoPistaParaDecolar();
         break;
      }
   }
}

bool Airport::existsRunWayAvaible() {
   RunWay* runWay = getRunWayAvaible();
   if (runWay)
      return true;
   else 
      return false;
}

bool Airport::isOpenToUsingLanding() {
   return getLimitOfAirplanesInLanding() > 0;
}

int Airport::getLimitOfAirplanesInLanding() { 
   return limitOfAirplanesInLanding;
}

RunWay* Airport::getRunWayAvaible() {
   for (int i= 0 ; i < 3 ; i++ ) {
      if (runWaysIsAvaible(runWays[i]))
         return runWays[i];
   }
   throw NoRunWaysAvaible();
}

bool Airport::runWaysIsAvaible(RunWay* runWay) {
   if (runWay->isAvaible()) {
      if (! Direction::areTransversesDirections(windMonitoring->getActualWind()->getDirectionWind(), runWay->getDirectionRunWay())) 
         return true;
   }
   return false;
}

Airport* Airport::getInstance() {
   if (!instance)
      instance= new Airport();
   return instance;
}

void Airport::resetInstance() {
   if (instance)
      delete instance;
   instance= nullptr;
}