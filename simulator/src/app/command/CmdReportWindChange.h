#pragma once
#ifndef INCLUDED_CMD_REPORT_WIND_CHANGE
#define INCLUDED_CMD_REPORT_WIND_CHANGE

#include "Command.h"

class CmdReportWindChange :
   public Command
{
public:
   ~CmdReportWindChange() {}
   CmdReportWindChange() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_CMD_REPORT_WIND_CHANGE