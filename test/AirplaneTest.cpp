#include "gtest\gtest.h"
#include "gmock\gmock.h"
#include "Airplane.h"
#include "Airport.h"

class AirplaneTest : public testing::Test {
protected:
   void SetUp() {
      Airport* airport= Airport::getInstance();
      airport->setLimitOfAirplanesInLanding(2);
   }
   void TearDown() {
      Airport::resetInstance();
   }
};

TEST_F(AirplaneTest, RequestLandingAirPlane) {
   Airplane airplane("Boing 737");
   airplane.requestLanding();
   ASSERT_GT(airplane.getTimeFirstRequest(), 0);
}

TEST_F(AirplaneTest, TwoRequestLandingAirPlaneChagingWind) {
   WindMonitoring* windMonitoring= WindMonitoring::getInstance();

   Airplane airplaneB("Boing 737");
   Airplane airplaneS("Spacex");

   airplaneB.requestLanding();
   windMonitoring->directionWindChange(314);
   airplaneS.requestLanding();

   ASSERT_GT(airplaneB.getTimeFirstRequest(), 0);
   ASSERT_GT(airplaneS.getTimeFirstRequest(), 0);
}

TEST_F(AirplaneTest, TwoRequestLandingAirPlaneNotChagingWind) {
   WindMonitoring* windMonitoring= WindMonitoring::getInstance();

   Airplane airplaneB("Boing 737");
   Airplane airplaneS("Spacex");

   airplaneB.requestLanding();
   airplaneS.requestLanding();

   ASSERT_GT(airplaneB.getTimeFirstRequest(), 0);
   ASSERT_GT(airplaneS.getTimeFirstRequest(), 0);
}