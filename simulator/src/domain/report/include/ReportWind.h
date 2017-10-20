#pragma once

#ifndef INCLUDED_REPORT_WIND_H
#define INCLUDED_REPORT_WIND_H

#include "Report.h"

class ReportWind :
   public Report
{
public:
   ~ReportWind() {}
   ReportWind() {}

   std::string generatingReport();
};

#endif // INCLUDED_REPORT_WIND_H