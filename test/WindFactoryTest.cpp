#include "gtest\gtest.h"
#include "WindFactory.h"
#include "Wind.h"

class WindFactoryTest : public testing::Test 
{
protected:
   WindFactory* factory;

   void SetUp() {
      factory= new WindFactory();
   }
   void TearDown() {
      delete factory;
   }
};

TEST_F(WindFactoryTest, CreateNorthWind) {
   Wind* wind= factory->makeWindStatus(355);
   ASSERT_EQ(Direction::NORTH, wind->getDirectionWind());
}

TEST_F(WindFactoryTest, CreateSouthWind) {
   Wind* wind= factory->makeWindStatus(202.5);
   ASSERT_EQ(Direction::SOUTH, wind->getDirectionWind());
}

TEST_F(WindFactoryTest, CreateWestWind) {
   Wind* wind= factory->makeWindStatus(292.5);
   ASSERT_EQ(Direction::WEST, wind->getDirectionWind());
}

TEST_F(WindFactoryTest, CreateEastWind) {
   Wind* wind= factory->makeWindStatus(91);
   ASSERT_EQ(Direction::EAST, wind->getDirectionWind());
}

TEST_F(WindFactoryTest, CreateNortheastWind) {
   Wind* wind= factory->makeWindStatus(22.6);
   ASSERT_EQ(Direction::NORTHEAST, wind->getDirectionWind());
}

TEST_F(WindFactoryTest, CreateSouthwestWind) {
   Wind* wind= factory->makeWindStatus(203);
   ASSERT_EQ(Direction::SOUTHWEST, wind->getDirectionWind());
}

TEST_F(WindFactoryTest, WindDegreeBelow0) {
   ASSERT_THROW(Wind* wind= factory->makeWindStatus(-15), WindFactory::DegreeWindException);
}

TEST_F(WindFactoryTest, WindDegreeBAbove360) {
   ASSERT_THROW(Wind* wind= factory->makeWindStatus(597), WindFactory::DegreeWindException);
}