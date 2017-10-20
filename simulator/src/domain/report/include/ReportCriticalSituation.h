#pragma once

#ifndef INCLUDED_REPORT_CRITICAL_SITUATIONS_H
#define INCLUDED_REPORT_CRITICAL_SITUATIONS_H

#include "Report.h"

class ReportCriticalSituation:
   public Report 
{
public:
   ~ReportCriticalSituation() {}
   ReportCriticalSituation() {}

   std::string generatingReport();
};

#endif // INCLUDED_REPORT_CRITICAL_SITUATIONS_H