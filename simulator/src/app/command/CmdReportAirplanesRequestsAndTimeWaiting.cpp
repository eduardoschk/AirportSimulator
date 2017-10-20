#include "MyData.h"
#include "Report.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportAirplanesRequestsAndTimeWaiting.h"

void CmdReportAirplanesRequestsAndTimeWaiting::execute(MyData& data, UserInterface& ui) {
   Report* report= data.getReportController().generateReport(REPORT_AIRPLANES_WAITING);
   ui.showMessage(report->generatingReport());
   delete report;
}
