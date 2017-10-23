#include "ReportWind.h"
#include "ReportFactory.h"
#include "ReportAirplanes.h"
#include "ReportPassengers.h"
#include "ReportAirplanesWaiting.h"
#include "ReportAirplanesOnGround.h"
#include "ReportCriticalSituation.h"

// Return nullptr if report type are wrong

Report* ReportFactory::makeReport(REPORTTYPE type) 
{
   switch (type) 
   {
   case REPORT_AIRPLANES_LANDING:    return new ReportAirplanes();
   case REPORT_AIRPLANES_ON_GROUND:  return new ReportAirplanesOnGround();
   case REPORT_AIRPLANES_WAITING:    return new ReportAirplanesWaiting();
   case REPORT_CRITICAL_SITUATION:   return new ReportCriticalSituation();
   case REPORT_PASSENGERS:           return new ReportPassengers();
   case REPORT_WIND:                 return new ReportWind();
   default:                          return nullptr;
   }
}