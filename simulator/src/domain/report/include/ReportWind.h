#pragma once

#ifndef REPORT_WIND_H
#define REPORT_WIND_H
#include "Report.h"

class ReportWind :
   public Report
{
public:
   ~ReportWind();
   ReportWind(); 

   std::string generatingReport();
};

#endif // REPORT_WIND_H