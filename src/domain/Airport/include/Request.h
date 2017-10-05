#pragma once
#include "Airplane.h"

class Request
{
protected:
   Airplane* airplane;

public:
   enum TYPEREQUEST {LANDING, TAKEOFF};

   Airplane* getAirplane() { return airplane; }
   virtual TYPEREQUEST getTypeRequest() = 0;
   virtual void resolve() = 0;
};

class LandingRequest : public Request {
public:
   LandingRequest(Airplane* _airplane) {
      airplane= _airplane;
   }
   
   TYPEREQUEST getTypeRequest() { return TYPEREQUEST::LANDING; }
   
   void resolve() {
      
   }
};

class TakeOffRequest : public Request {
public:
   TakeOffRequest(Airplane* _airplane) {
      airplane= _airplane;
   }
   TYPEREQUEST getTypeRequest() { return TYPEREQUEST::TAKEOFF; }
   
   void resolve() {
      
   }
};