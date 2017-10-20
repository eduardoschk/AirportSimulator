#include <sstream>
#include "ReportAirplanesOnGround.h"
#include "TowerOfControl.h"

std::string ReportAirplanesOnGround::generatingReport() 
{
   std::stringstream ss;
   ss << "Número de aviões em solo no momento: " << TowerOfControl::getInstance()->getNumberAirplanesOnGround() << "\n";
   return ss.str();
}
