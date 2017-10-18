#include "ReportFactory.h"
#include "ReportAirplanes.h"
#include "ReportAirplanesOnGround.h"
#include "ReportAirplanesWaiting.h"
#include "ReportCriticalSituation.h"
#include "ReportPassengers.h"
#include "ReportWind.h"

Report* ReportFactory::makeReport(REPORTTYPE type) {
   switch (type) {
   case AIRPLANESLANDING:     return new ReportAirplanes();
   case AIRPLANESONGROUND:    return new ReportAirplanesOnGround();
   case AIRPLANESWAITING:     return new ReportAirplanesWaiting();
   case CRITICALSITUATION:    return new ReportCriticalSituation();
   case PASSENGERS:           return new ReportPassengers();
   case WIND:                 return new ReportWind();
   }
}