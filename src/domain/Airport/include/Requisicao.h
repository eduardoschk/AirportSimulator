#pragma once

class Airplane;

class Requisicao
{
public:
   enum TYPEREQUEST {POUSO, DECOLAR};
private:
   Airplane* airplane;
   TYPEREQUEST typeRequest;

public:
   Requisicao(Airplane* _airplane, TYPEREQUEST type) : airplane(_airplane), typeRequest(type) {}
   ~Requisicao() {}

   Airplane* getAirplane() { return airplane; }
   TYPEREQUEST getTypeRequest() { return typeRequest; }
};

