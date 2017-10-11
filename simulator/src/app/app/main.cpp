#include "App.h"

#include <crtdbg.h>

void main() {

   _CrtMemState s1,s2;
   _CrtMemCheckpoint(&s1);

   App().runApp();

   _CrtMemCheckpoint(&s2);
   _CrtDumpMemoryLeaks();
}