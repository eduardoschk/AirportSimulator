#include "RunWay.h"
#include "Cronometro.h"
#include <iostream>
#include "CallBack.h"

RunWay::RunWay(Direction::DIRECTIONS _directionRunWay) : directionRunWay(_directionRunWay), landingAvaible(true) {}

void RunWay::runwayInUse() {
   landingAvaible= false;
   CallBack<RunWay>* cron= new CallBack<RunWay>(this, &RunWay::outroTeste);
   Cronometro(cron).run(5);
}

void RunWay::outroTeste() {
   std::cout << "Outro teste" << std::endl;
}