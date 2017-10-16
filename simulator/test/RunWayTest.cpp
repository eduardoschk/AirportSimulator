#pragma once
#include <time.h>
#include "RunWay.h"
#include "gtest\gtest.h"
#include "Direction.h"
#include "MyTimer.h"

class RunWayTest : 
   public testing::Test 
{
protected:
   RunWay* runWay;
   MyTimer* timer;
   void SetUp() {
      runWay= new RunWay(Direction::SOUTH);
      timer= MyTimer::getTimer();
   }
   void TearDown() {
      delete runWay;
   }
};

TEST_F(RunWayTest, IsAvaibleRunWay) {
   ASSERT_TRUE(runWay->isAvailable());
}

TEST_F(RunWayTest, IsUnavaibleRunWay) {
   runWay->runwayPutToUse();
   ASSERT_FALSE(runWay->isAvailable());
}

TEST_F(RunWayTest, TimeUnavailable1Second) {
   runWay->runwayPutToUse();
   timer->startStopwatch(1);
   ASSERT_FALSE(runWay->isAvailable());
}

TEST_F(RunWayTest, TimeUnavailable3Seconds) {
   runWay->runwayPutToUse();
   timer->startStopwatch(3);
   ASSERT_TRUE(runWay->isAvailable());
}