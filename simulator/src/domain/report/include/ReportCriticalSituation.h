#pragma once

#ifndef REPORT_CRITICAL_SITUATIONS_H
#define REPORT_CRITICAL_SITUATIONS_H
#include "Report.h"

class ReportCriticalSituation:
   public Report 
{
public:
   ~ReportCriticalSituation();
   ReportCriticalSituation();

   std::string generatingReport();
};

#endif // REPORT_CRITICAL_SITUATIONS_H