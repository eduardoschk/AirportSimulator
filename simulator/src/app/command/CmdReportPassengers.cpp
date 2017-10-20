#include "MyData.h"
#include "Report.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportPassengers.h"

void CmdReportPassengers::execute(MyData& data, UserInterface& ui) {
   Report* report= data.getReportController().generateReport(REPORT_PASSENGERS);
   ui.showMessage(report->generatingReport());
   delete report;
}
