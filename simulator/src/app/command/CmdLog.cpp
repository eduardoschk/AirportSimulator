#include "CmdLog.h"
#include "MyData.h"
#include "MyTimer.h"
#include "UserInterface.h"
#include "ReportController.h"

void CmdLog::execute(MyData& data, UserInterface& ui) 
{  
   int continued= 1;
   while (continued)
   {
      monitoringFor20Seconds(data, ui);
      continued= ui.requestOption("Digite 0 para sair do modo de monitoramento ou qualquer outro número para continuar ");
   }
}

void CmdLog::checkBufferEvents(MyData& data, UserInterface& ui)
{
   while (data.getReportController().hasEvent())
   {
      ui.showMessage(data.getReportController().getEvent().message);
   }
}

void CmdLog::monitoringFor20Seconds(MyData& data, UserInterface& ui)
{
   for(int seconds= 1 ; seconds < 20 ; data.getTimer().sleep(1), ++seconds) {
      checkBufferEvents(data, ui);
   }
}
