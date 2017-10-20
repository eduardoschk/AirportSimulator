#pragma once
#ifndef INCLUDED_CMD_REPORT_AIRPLANES_REQUEST_AND_TIME_WAITING
#define INCLUDED_CMD_REPORT_AIRPLANES_REQUEST_AND_TIME_WAITING

#include "Command.h"

class CmdReportAirplanesRequestsAndTimeWaiting :
   public Command
{
public:
   ~CmdReportAirplanesRequestsAndTimeWaiting() {}
   CmdReportAirplanesRequestsAndTimeWaiting() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_CMD_REPORT_AIRPLANES_REQUEST_AND_TIME_WAITING