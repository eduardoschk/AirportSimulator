#include "gtest/gtest.h"
#include "TowerOfControl.h"
#include "Airport.h"
#include "WindMonitoring.h"
#include "MyTimer.h"

class AirportTest :
   public testing::Test
{
protected:
   TowerOfControl* tc;
   WindMonitoring* wm;

   void SetUp() {
      tc= TowerOfControl::getInstance();
      tc->setLimitAirplanes(3);

      wm= WindMonitoring::getInstance();
      wm->directionWindChange(350);
   }

   void TearDown() {
      delete wm;
      delete tc;
   }
};


TEST_F(AirportTest, AirplaneLandingCompleted) {
   Airplane *air1= new Airplane("Air1", 1);
   air1->requestLandingToAirport();
   EXPECT_GT(air1->getTimeAllowdLanding(), 0);
}

TEST_F(AirportTest, TwoAirplaneLandingOnlyOneCompleted) {
   Airplane *air1= new Airplane("Air1", 1);
   Airplane *air2= new Airplane("Air2", 1);

   air1->requestLandingToAirport();
   air2->requestLandingToAirport();

   EXPECT_GT(air1->getTimeAllowdLanding(), 0);
   EXPECT_EQ(air2->getTimeAllowdLanding(), 0);
}

TEST_F(AirportTest, TwoAirplaneLandingWithChangeWind) {
   Airplane *air1= new Airplane("Air1", 1);
   Airplane *air2= new Airplane("Air2", 1);

   air1->requestLandingToAirport();
   wm->directionWindChange(270);
   air2->requestLandingToAirport();

   EXPECT_GT(air1->getTimeAllowdLanding(), 0);
   EXPECT_GT(air2->getTimeAllowdLanding(), 0);
}

TEST_F(AirportTest, aviaoAguardaLiberacaoDeAngar) {
   Airplane *air1= new Airplane("Air1", 1);
   Airplane *air2= new Airplane("Air2", 1);

   tc->setLimitAirplanes(1);

   air1->requestLandingToAirport();
   air2->requestLandingToAirport();
   air1->requestTakeOffToAirport();
   EXPECT_EQ(air2->getTimeAllowdLanding(), 0);
   MyTimer::getTimer()->startStopwatch(6);
   EXPECT_GT(air2->getTimeAllowdLanding(), 0);
}

TEST_F(AirportTest, filaDeRequisicoes) {
   wm->directionWindChange(315);
   
   Airplane *air1= new Airplane("Air1", 1);
   Airplane *air2= new Airplane("air2", 1);

   air1->requestLandingToAirport();
   air2->requestLandingToAirport();

   air1->changedAirport();

   wm->directionWindChange(350);

   MyTimer::getTimer()->startStopwatch(3);

   ASSERT_EQ(air1->getTimeAllowdLanding(), 0);
   ASSERT_GT(air2->getTimeAllowdLanding(), 0);
}
