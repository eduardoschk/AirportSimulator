#include "MyData.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportCriticalSituations.h"

void CmdReportCriticalSituations::execute(MyData& data, UserInterface& ui) {
   ui.showMessage(data.getReportController().getReportResult(REPORT_CRITICAL_SITUATION));
}
