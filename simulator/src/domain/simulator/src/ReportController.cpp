#include "ReportController.h"
#include "ReportFactory.h"
#include "Report.h";
#include "Log.h"

ReportController::ReportController() : log(Log::getInstance()), factory(new ReportFactory()) {}

std::string ReportController::generateReport(REPORTTYPE type) {
   return factory->makeReport(type)->generatingReport();
}
