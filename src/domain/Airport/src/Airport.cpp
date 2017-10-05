#include "Airport.h"
#include <iostream>
#include "Direction.h"

Airport::Airport() : windMonitoring(WindMonitoring::getInstance())
{
   runWays[0]= new RunWay(Direction::SOUTH);
   runWays[1]= new RunWay(Direction::WEST);
   runWays[2]= new RunWay(Direction::SOUTHEAST);
}

///////////////////////////////////////////////////////////////////////////////

bool Airport::existsRunWayAvaible() {
   RunWay* runWay = getRunWayAvaible();
   if (runWay)
      return true;
   else 
      return false;
}

RunWay* Airport::getRunWayAvaible() {
   for (int i= 0 ; i < 3 ; i++ ) {
      if (runWaysIsAvaible(runWays[i]))
         return runWays[i];
   }
   return nullptr;
}

bool Airport::runWaysIsAvaible(RunWay* runWay) {
   if (runWay->isAvaible()) {
      if (! Direction::areTransversesDirections(windMonitoring->getActualWind()->getDirectionWind(), runWay->getDirectionRunWay())) 
         return true;
   }
   return false;
}

void Airport::requestUseAirport(Airplane* _airplane) {
   std::cout << "Requisicao recebida" << std::endl;
   Request* request= new LandingRequest(_airplane);
   requests.push(request);
   verifyRequests();
}

void Airport::verifyRequests() {
   if (!requests.empty()) {
      if (existsRunWayAvaible()) {
         Request* req= requests.front();
         RunWay* runWay= getRunWayAvaible();
         runWay->runwayInUse();
         requests.pop();
         std::cout << req->getAirplane()->getName() << " pousando na pista " << Direction::toString(runWay->getDirectionRunWay()) << std::endl;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
///// Singleton ///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

static Airport* instance = nullptr;

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