#pragma once
#include "Airplane.h"

class Request
{
protected:
   Airplane* airplane;

public:
   virtual~ Request() {}

   enum TYPEREQUEST {LANDING, TAKEOFF};

   Airplane* getAirplane() { return airplane; }
   virtual TYPEREQUEST getTypeRequest() = 0;
};

class LandingRequest : public Request {
public:
   LandingRequest(Airplane* _airplane) {
      airplane= _airplane;
   }
   
   TYPEREQUEST getTypeRequest() { return TYPEREQUEST::LANDING; }
   
};

class TakeOffRequest : public Request {
public:
   ~TakeOffRequest() { 
      delete airplane;
   }

   TakeOffRequest(Airplane* _airplane) {
      airplane= _airplane;
   }
   TYPEREQUEST getTypeRequest() { return TYPEREQUEST::TAKEOFF; }
};