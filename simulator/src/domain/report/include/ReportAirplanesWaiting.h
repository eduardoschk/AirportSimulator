#pragma once

#ifndef REPORT_AIRPLANES_WAITING_H
#define REPORT_AIRPLANES_WAITING_H
#include "Report.h"

class ReportAirplanesWaiting :
   public Report
{
public:
   ReportAirplanesWaiting();
   ~ReportAirplanesWaiting();

   std::string generatingReport();
};

#endif // REPORT_AIRPLANES_WAITING_H