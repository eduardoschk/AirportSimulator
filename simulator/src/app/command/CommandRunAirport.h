#pragma once
#ifndef COMMAND_RUN_AIRPORT_H
#define COMMAND_RUN_AIRPORT_H

#include "Command.h"

class CommandRunAirport :
   public Command
{
public:
   CommandRunAirport() {}
   ~CommandRunAirport() {}

   void execute(MyData& data, UserInterface& ui);
};

#endif