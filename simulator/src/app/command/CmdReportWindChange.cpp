#include "MyData.h"
#include "Report.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportWindChange.h"

void CmdReportWindChange::execute(MyData& data, UserInterface& ui) {
   Report* report= data.getReportController().generateReport(REPORT_WIND);
   ui.showMessage(report->generatingReport());
   delete report;
}
