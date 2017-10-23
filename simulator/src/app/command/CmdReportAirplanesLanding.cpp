#include "MyData.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportAirplanesLanding.h"

void CmdReportAirplanesLanding::execute(MyData& data, UserInterface& ui) 
{
   ui.showMessage(data.getReportController().getReportResult(REPORT_AIRPLANES_LANDING));
}