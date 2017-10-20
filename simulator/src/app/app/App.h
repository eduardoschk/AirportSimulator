#pragma once

#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class UserInterface;
class MyData;
class Command;

class App
{
private:
   MyData* data;
   UserInterface* ui;
   Command* currentCmd;

   void runApp();
   void initAirport();

   bool executeCmd();
   void cleanCurrentCmd();
   bool createCmd(int menuOption);

public:
   ~App();
   App();

   void run();
};

#endif // INCLUDED_APP_H