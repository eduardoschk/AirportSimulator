#pragma once
#include "GenericCallBack.h"

template <class T>
class CallBack : public GenericCallBack {
public:
   typedef void(T::*action)();

   CallBack( T* object, action method ) : m_object(object), m_method(method) {} 
   ~CallBack() {}

   void execute(){
      (m_object->*m_method)();
   }

private:
   T* m_object;
   action m_method;
};