#include "MyTimer.h"
#include "MyRandom.h"
#include "WindController.h"
#include "WindMonitoring.h"

WindController::WindController() : timer(MyTimer::getTimer()), windMonitoring(WindMonitoring::getInstance()) 
{
   calculateTimeWindChange();
   timer->addObserver(this);
}

WindController::~WindController() 
{
   delete windMonitoring;
   timer->removeObserver(this);
}

///////////////////////////////////////////////////////////////////////////////

void WindController::changeWind() 
{
   windMonitoring->directionWindChange( MyRandom::generateRandomValueBetween(0, 36) * 10 ); 
   calculateTimeWindChange();
}

void WindController::calculateTimeWindChange() 
{
   timeToChangeWind= timer->getActualTime() + MyRandom::generateRandomValueBetween(4, 10);
}

///////////////////////////////////////////////////////////////////////////////

void WindController::updateTime(const long time) 
{
   if (time >= timeToChangeWind) 
      changeWind();
}