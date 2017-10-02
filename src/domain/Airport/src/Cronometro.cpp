#include <iostream>
#include "Cronometro.h"

Cronometro::Cronometro( GenericCallBack* _callBack ) : callBack(_callBack) {
}

Cronometro::~Cronometro() {}

DWORD WINAPI runThreadSleep( LPVOID lpParam) {
   Sleep((long)lpParam);
   std::cout << "Terminando Thread" << std::endl;

   return 0;
}

void Cronometro::run( long timeSeconds) {
   thread = CreateThread( NULL, 0, runThreadSleep, (LPVOID)(this), 0, NULL);
}