#pragma once
#ifndef INCLUDED_CMD_REPORT_AIRPLANES_LANDING
#define INCLUDED_CMD_REPORT_AIRPLANES_LANDING

#include "Command.h"

class CmdReportAirplanesLanding :
   public Command
{
public:
   ~CmdReportAirplanesLanding() {}
   CmdReportAirplanesLanding() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_CMD_REPORT_AIRPLANES_LANDING