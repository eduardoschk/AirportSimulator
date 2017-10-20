#pragma once

#ifndef INCLUDED_REPORT_AIRPLANE_H
#define INCLUDED_REPORT_AIRPLANE_H

#include "Report.h"

class ReportAirplanes :
   public Report
{
public:
   ~ReportAirplanes() {}
   ReportAirplanes() {}

   std::string generatingReport();
};

#endif // INCLUDED_REPORT_AIRPLANE_H