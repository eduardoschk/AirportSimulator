#pragma once
#ifndef INCLUDED_REQUEST_H
#define INCLUDED_REQUEST_H

#include "Airplane.h"

class Request
{
protected:
   Airplane* airplane;

public:
   virtual~ Request() {}
   Request() {}

   enum TYPEREQUEST {REQUEST_LANDING, REQUEST_TAKEOFF};

   Airplane* getAirplane() { return airplane; }

   virtual TYPEREQUEST getTypeRequest() = 0;
   virtual std::string getStringTypeRequest() = 0;
};

class LandingRequest : 
   public Request 
{
public:
   LandingRequest(Airplane* _airplane) {
      airplane= _airplane;
   }
   
   std::string getStringTypeRequest() { return "Pouso"; }
   TYPEREQUEST getTypeRequest() { return TYPEREQUEST::REQUEST_LANDING; }
};

class TakeOffRequest : 
   public Request 
{
public:
   ~TakeOffRequest() { 
      delete airplane;
   }

   TakeOffRequest(Airplane* _airplane) {
      airplane= _airplane;
   }

   std::string getStringTypeRequest() { return "Decolagem"; }
   TYPEREQUEST getTypeRequest() { return TYPEREQUEST::REQUEST_TAKEOFF; }
};

#endif // INCLUDED_REQUEST_H