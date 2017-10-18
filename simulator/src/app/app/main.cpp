#include "App.h"

#include <crtdbg.h>

void main() {

   _CrtMemState s1,s2;
   _CrtMemCheckpoint(&s1);

   App().run();

   _CrtMemCheckpoint(&s2);
   _CrtDumpMemoryLeaks();
}