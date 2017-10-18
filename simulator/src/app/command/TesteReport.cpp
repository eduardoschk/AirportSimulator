#include "TesteReport.h"
#include "UserInterface.h"
#include "MyData.h"

void TesteReport::execute(MyData& data, UserInterface& ui) {
   ui.showMessage(data.getReportController()->generateReport(AIRPLANESLANDING));
}