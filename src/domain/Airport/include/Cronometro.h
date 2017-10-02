#pragma once

#include <Windows.h>
#include "GenericCallBack.h"

class Cronometro
{
private:
   HANDLE thread;
   GenericCallBack* callBack;

public:
   Cronometro(GenericCallBack* _callBack);
   ~Cronometro();

   void run(long timeSeconds);
};