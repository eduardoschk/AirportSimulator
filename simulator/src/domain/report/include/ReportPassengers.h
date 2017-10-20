#pragma once

#ifndef INCLUDED_REPORT_PASSENGERS_H
#define INCLUDED_REPORT_PASSENGERS_H

#include "Report.h"

class ReportPassengers :
   public Report
{
public:
   ~ReportPassengers() {}
   ReportPassengers() {}

   std::string generatingReport();
};

#endif // INCLUDED_REPORT_PASSENGERS_H