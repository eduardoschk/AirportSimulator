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

TEST_F(WindMonitoringTest, NoTransversalDirections) {
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::SOUTH, Direction::NORTH));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::NORTH, Direction::SOUTH));

   ASSERT_FALSE(Direction::areTransversesDirections(Direction::WEST, Direction::EAST));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::EAST, Direction::WEST));

   ASSERT_FALSE(Direction::areTransversesDirections(Direction::NORTHWEST, Direction::SOUTHEAST));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::SOUTHEAST, Direction::NORTHWEST));

   ASSERT_FALSE(Direction::areTransversesDirections(Direction::NORTHEAST, Direction::SOUTHWEST));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::SOUTHWEST, Direction::NORTHEAST));
}

TEST_F(WindMonitoringTest, AreTransversesDirections) {
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::SOUTH, Direction::WEST));
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::NORTH, Direction::NORTHWEST));
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::SOUTHEAST, Direction::NORTH));
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::WEST, Direction::NORTHEAST));
}