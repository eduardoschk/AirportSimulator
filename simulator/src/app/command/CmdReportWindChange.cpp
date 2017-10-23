#include "MyData.h"
#include "UserInterface.h"
#include "ReportController.h"
#include "CmdReportWindChange.h"

void CmdReportWindChange::execute(MyData& data, UserInterface& ui) {
   ui.showMessage(data.getReportController().getReportResult( REPORT_WIND));
}
