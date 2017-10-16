#include "gtest/gtest.h"
#include "Airplane.h"
#include "WindMonitoring.h"
#include "TowerOfControl.h"
#include "MyTimer.h"

class AirplaneTest :
   public testing::Test
{
protected:
   TowerOfControl* tc;
   WindMonitoring* wm;

   void SetUp() {
      tc= TowerOfControl::getInstance();
      tc->setLimitAirplanes(3);

      wm= WindMonitoring::getInstance();
      wm->directionWindChange(350); // NORTH
   }

   void TearDown() {
      delete wm;
      delete tc;
   }
};

TEST_F(AirplaneTest, RequestLandingToTowerOfControl) {
   Airplane *air1= new Airplane("Air1", 1);
   air1->requestLandingToAirport();
   EXPECT_GT(air1->getTimeLimitResponseLandingRequest(), 0);
}

TEST_F(AirplaneTest, RequestTakeOffToTowerOfControl) {
   Airplane *air1= new Airplane("Air1", 1);
   air1->requestTakeOffToAirport();
}