#pragma once
#ifndef INCLUDED_CMD_LOG
#define INCLUDED_CMD_LOG

#include "Command.h"

class CmdLog :
   public Command
{
public:
   ~CmdLog() {}
   CmdLog() {}

   void execute(MyData& data, UserInterface& ui);
   void checkBufferEvents(MyData& data, UserInterface& ui);
   void monitoringFor20Seconds(MyData& data, UserInterface& ui);
};

#endif // INCLUDED_CMD_LOG