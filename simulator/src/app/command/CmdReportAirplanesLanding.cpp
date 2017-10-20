#include "MyData.h"
#include "Report.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportAirplanesLanding.h"

void CmdReportAirplanesLanding::execute(MyData& data, UserInterface& ui) 
{
   Report* report= data.getReportController().generateReport(REPORT_AIRPLANES_LANDING);
   ui.showMessage(report->generatingReport());
   delete report;
}