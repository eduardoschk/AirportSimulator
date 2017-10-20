#pragma once

#ifndef INCLUDED_REPORT_AIRPLANES_ON_GROUND_H
#define INCLUDED_REPORT_AIRPLANES_ON_GROUND_H

#include "Report.h"

class ReportAirplanesOnGround :
   public Report
{
public:
   ~ReportAirplanesOnGround() {}
   ReportAirplanesOnGround() {}

   std::string generatingReport();
};

#endif // INCLUDED_REPORT_AIRPLANES_ON_GROUND_H