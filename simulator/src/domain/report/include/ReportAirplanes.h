#pragma once

#ifndef REPORT_AIRPLANE_H
#define REPORT_AIRPLANE_H

#include "Report.h"

class ReportAirplanes :
   public Report
{
public:
   ~ReportAirplanes();
   ReportAirplanes();

   std::string generatingReport();
};

#endif // REPORT_AIRPLANE_H