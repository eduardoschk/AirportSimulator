#include "MyData.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportAirplanesRequestsAndTimeWaiting.h"

void CmdReportAirplanesRequestsAndTimeWaiting::execute(MyData& data, UserInterface& ui) {
   ui.showMessage(data.getReportController().getReportResult(REPORT_AIRPLANES_WAITING));
}
