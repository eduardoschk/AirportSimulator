#pragma once

#ifndef COMMAND_H
#define COMMAND_H

class MyData;
class UserInterface;

class Command {
public:
   virtual ~Command() {}
   Command() {}

   virtual void execute(MyData& data, UserInterface& ui) = 0;
};

#endif // COMMAND_H