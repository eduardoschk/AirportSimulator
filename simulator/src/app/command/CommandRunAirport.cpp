#include "CommandRunAirport.h"
#include "UserInterface.h"
#include "MyData.h"

void CommandRunAirport::execute(MyData& data, UserInterface& ui) {
   data.getControllerTowerOfControl()->setLimitAirplanes(ui.requestOption("Quantos aviões poderão pousar?"));
   data.getTimer()->startStopwatch(ui.requestOption("Por quantos segundos?"));
}
