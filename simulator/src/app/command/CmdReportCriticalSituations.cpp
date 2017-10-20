#include "MyData.h"
#include "Report.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportCriticalSituations.h"

void CmdReportCriticalSituations::execute(MyData& data, UserInterface& ui) {
   Report* report= data.getReportController().generateReport(REPORT_CRITICAL_SITUATION);
   ui.showMessage(report->generatingReport());
   delete report;
}
