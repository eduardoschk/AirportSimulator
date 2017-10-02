#pragma once
#include "RunWay.h"
#include "gtest\gtest.h"
#include "Direction.h"

class RunWayTest {
};

TEST(RunWayTest, IsAvaibleRunWay) {
   RunWay runWay(Direction::SOUTH);
   ASSERT_TRUE(runWay.isAvaible());
}

TEST(RunWayTest, NoTransversalDirections) {
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::SOUTH, Direction::NORTH));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::NORTH, Direction::SOUTH));

   ASSERT_FALSE(Direction::areTransversesDirections(Direction::WEST, Direction::EAST));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::EAST, Direction::WEST));

   ASSERT_FALSE(Direction::areTransversesDirections(Direction::NORTHWEST, Direction::SOUTHEAST));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::SOUTHEAST, Direction::NORTHWEST));

   ASSERT_FALSE(Direction::areTransversesDirections(Direction::NORTHEAST, Direction::SOUTHWEST));
   ASSERT_FALSE(Direction::areTransversesDirections(Direction::SOUTHWEST, Direction::NORTHEAST));
}

TEST(RunWayTest, AreTransversesDirections) {
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::SOUTH, Direction::WEST));
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::NORTH, Direction::NORTHWEST));
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::SOUTHEAST, Direction::NORTH));
   ASSERT_TRUE(Direction::areTransversesDirections(Direction::WEST, Direction::NORTHEAST));
}

