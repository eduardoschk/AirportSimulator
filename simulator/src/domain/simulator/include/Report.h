#pragma once

#ifndef INCLUDED_REPORT_H
#define INCLUDED_REPORT_H

#include <string>

class Report
{
public:
   virtual ~Report() {}
   Report() {}

   virtual std::string generatingReport() = 0;
};

#endif // INCLUDED_REPORT_H
