#pragma once

#include <string>

class Log;
class ReportFactory;

enum REPORTTYPE {AIRPLANESLANDING, AIRPLANESONGROUND, AIRPLANESWAITING, CRITICALSITUATION, PASSENGERS, WIND};

class ReportController
{
private:
   Log *log;
   ReportFactory *factory;
public:
   ReportController();
   ~ReportController() {}

   std::string generateReport(REPORTTYPE type);
};

