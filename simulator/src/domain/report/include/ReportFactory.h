#pragma once
#ifndef INCLUDED_REPORT_FACTORY_H
#define INCLUDED_REPORT_FACTORY_H

#include "ReportController.h"
class Report;

class ReportFactory
{
public:
   ReportFactory() {}
   ~ReportFactory() {}

   Report* makeReport(REPORTTYPE type);
};

#endif // INCLUDED_REPORT_FACTORY_H