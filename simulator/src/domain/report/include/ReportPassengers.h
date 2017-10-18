#pragma once

#ifndef REPORT_PASSENGERS_H
#define REPORT_PASSENGERS_H
#include "Report.h"

class ReportPassengers :
   public Report
{
public:
   ~ReportPassengers() {}
   ReportPassengers() {}

   std::string generatingReport();
};

#endif // REPORT_PASSENGERS_H