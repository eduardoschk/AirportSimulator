#include "gtest\gtest.h"
#include "WindMonitoring.h"
#include "Wind.h"

class WindMonitoringTest : public testing::Test
{
   protected:
      WindMonitoring* monitoring;

   void SetUp() {
      monitoring= WindMonitoring::getInstance();
   }
};

TEST_F( WindMonitoringTest, ChangeDirectionWind ) {
   monitoring->directionWindChange(37);
   ASSERT_EQ(Direction::NORTHEAST, monitoring->getActualWind()->getDirectionWind());
}

TEST_F( WindMonitoringTest, ChangeTwoDirectionWind ) {
   monitoring->directionWindChange(37);
   ASSERT_EQ(Direction::NORTHEAST, monitoring->getActualWind()->getDirectionWind());
   monitoring->directionWindChange(293);
   ASSERT_EQ(Direction::NORTHWEST, monitoring->getActualWind()->getDirectionWind());
}

