#include "MyData.h"
#include "Report.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportAirplanesOnGround.h"

void CmdReportAirplanesOnGround::execute(MyData& data, UserInterface& ui) {
   Report* report= data.getReportController().generateReport(REPORT_AIRPLANES_ON_GROUND);
   ui.showMessage(report->generatingReport());
   delete report;
}
