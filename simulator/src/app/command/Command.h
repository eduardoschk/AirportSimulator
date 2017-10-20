#pragma once

#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

class MyData;
class UserInterface;

class Command {
public:
   virtual ~Command() {}
   Command() {}

   virtual void execute(MyData& data, UserInterface& ui) = 0;
};

#endif // INCLUDED_COMMAND_H