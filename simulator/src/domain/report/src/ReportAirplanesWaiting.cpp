#include "ReportAirplanesWaiting.h"
#include "Log.h"
#include "TowerOfControl.h"

ReportAirplanesWaiting::~ReportAirplanesWaiting() {}

ReportAirplanesWaiting::ReportAirplanesWaiting() {}

std::string ReportAirplanesWaiting::generatingReport() {
   std::stringstream ss;
   std::deque<Request*> requests= TowerOfControl::getInstance()->getRequests();

   ss << "N�mero de avi�es aguardando resposta do aeroporto: " << requests.size() << "\n";

   for (std::deque<Request*>::iterator iter= requests.begin() ; iter != requests.end() ; ++iter) {
      Request* request= dynamic_cast<Request*>(*iter);
      if (request->getTypeRequest() == Request::LANDING) 
         ss << "Avi�o " << request->getAirplane()->getName() << " solicitou " << request->getStringTypeRequest() << " � " << (MyTimer::getActualTime() - request->getAirplane()->getTimeRequestLanding()) * 4 << " minutos \n";
      else
         ss << "Avi�o " << request->getAirplane()->getName() << " solicitou " << request->getStringTypeRequest() << " � " << (MyTimer::getActualTime() - request->getAirplane()->getTimeToNextFlight()) * 4 << " minutos \n";
   }

   return ss.str();
}