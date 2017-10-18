#pragma once
#ifndef REPORT_FACTORY_H
#define REPORT_FACTORY_H

#include "ReportController.h"
class Report;

class ReportFactory
{
public:
   ReportFactory() {}
   ~ReportFactory() {}

   Report* makeReport(REPORTTYPE type);
};

#endif