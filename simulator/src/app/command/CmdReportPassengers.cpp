#include "MyData.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportPassengers.h"

void CmdReportPassengers::execute(MyData& data, UserInterface& ui) {
   ui.showMessage(data.getReportController().getReportResult(REPORT_PASSENGERS));
}
