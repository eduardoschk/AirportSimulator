#pragma once
#ifndef INCLUDED_CMD_REPORT_AIRPLANES_ON_GROUND
#define INCLUDED_CMD_REPORT_AIRPLANES_ON_GROUND

#include "Command.h"

class CmdReportAirplanesOnGround :
   public Command
{
public:
   ~CmdReportAirplanesOnGround() {}
   CmdReportAirplanesOnGround() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_CMD_REPORT_AIRPLANES_ON_GROUND