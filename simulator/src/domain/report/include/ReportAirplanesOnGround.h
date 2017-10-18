#pragma once

#ifndef REPORT_AIRPLANES_ON_GROUND_H
#define REPORT_AIRPLANES_ON_GROUND_H

#include "Report.h"

class ReportAirplanesOnGround :
   public Report
{
public:
   ~ReportAirplanesOnGround();
   ReportAirplanesOnGround();

   std::string generatingReport();
};

#endif // REPORT_AIRPLANES_ON_GROUND_H