#include <sstream>
#include "ReportAirplanesOnGround.h"
#include "TowerOfControl.h"

ReportAirplanesOnGround::~ReportAirplanesOnGround() {}

ReportAirplanesOnGround::ReportAirplanesOnGround() {}

std::string ReportAirplanesOnGround::generatingReport() {
   std::stringstream ss;
   ss << "N�mero de avi�es em solo no momento: " << TowerOfControl::getInstance()->getNumberAirplanesOnGround() << "\n";
   return ss.str();
}
