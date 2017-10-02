//#include "gmock/gmock.h"
//#include "gtest/gtest.h"
#include "Airplane.h"
#include "Airport.h"
#include <Windows.h>

int main(int argc, char** argv) {
   //::testing::InitGoogleMock(&argc, argv);
   //return RUN_ALL_TESTS();

   Airport* airport= Airport::getInstance();
   airport->setLimitOfAirplanesInLanding(2);
   Airplane* airplane= new Airplane("Boing");

   airplane->requestLanding();

   Sleep(10000);
}