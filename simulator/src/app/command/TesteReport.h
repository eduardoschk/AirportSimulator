#pragma once
#include "command.h"

class MyData;
class UserInterface;

class TesteReport :
   public Command
{
public:
   TesteReport() {}
   ~TesteReport() {}

   void execute(MyData& data, UserInterface& ui);
};

