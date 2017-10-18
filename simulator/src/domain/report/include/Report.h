#pragma once

#ifndef REPORT_H
#define REPORT_H

#include <string>

class Report
{
public:
   virtual ~Report() {}
   Report() {}

   virtual std::string generatingReport() = 0;
};

#endif // REPORT_H
