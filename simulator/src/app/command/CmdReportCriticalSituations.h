#pragma once
#ifndef INCLUDED_REPORT_CMD_CRITICAL_SITUATION
#define INCLUDED_REPORT_CMD_CRITICAL_SITUATION

#include "Command.h"

class CmdReportCriticalSituations :
   public Command
{
public:
   ~CmdReportCriticalSituations() {}
   CmdReportCriticalSituations() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_REPORT_CMD_CRITICAL_SITUATION