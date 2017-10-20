#pragma once

#ifndef INCLUDED_REPORT_AIRPLANES_WAITING_H
#define INCLUDED_REPORT_AIRPLANES_WAITING_H

#include "Report.h"

class ReportAirplanesWaiting :
   public Report
{
public:
   ~ReportAirplanesWaiting() {}
   ReportAirplanesWaiting() {}

   std::string generatingReport();
};

#endif // INCLUDED_REPORT_AIRPLANES_WAITING_H