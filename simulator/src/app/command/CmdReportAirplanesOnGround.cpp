#include "MyData.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportAirplanesOnGround.h"

void CmdReportAirplanesOnGround::execute(MyData& data, UserInterface& ui) {
   ui.showMessage(data.getReportController().getReportResult(REPORT_AIRPLANES_ON_GROUND));
}
