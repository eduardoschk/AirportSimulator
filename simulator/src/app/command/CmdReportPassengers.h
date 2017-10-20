#pragma once
#ifndef INCLUDED_CMD_REPORT_PASSENGERS
#define INCLUDED_CMD_REPORT_PASSENGERS

#include "Command.h"

class CmdReportPassengers :
   public Command
{
public:
   ~CmdReportPassengers() {}
   CmdReportPassengers() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_CMD_REPORT_PASSENGERS