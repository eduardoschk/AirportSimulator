#pragma once

class Report
{
public:
   virtual ~Report();
   Report();

   virtual void generatingReport() = 0;
};