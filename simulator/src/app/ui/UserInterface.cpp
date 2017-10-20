#include <iostream>
#include <locale.h>
#include <windows.h>
#include "UserInterface.h"

UserInterface::UserInterface() 
{
   setlocale(LC_ALL, "Portuguese");
}

///////////////////////////////////////////////////////////////////////////////

int UserInterface::getMenuOptionAndShowMenu() 
{
   int option;
   std::cout   << "--- Menu de relat�rios --- \n"
               << "Escolha a op��o de relat�rio abaixo pelo seu respectivo index \n\n"
               << "1 - N�mero de avi�es pousados at� o momento \n"
               << "2 - N�mero de avi�es atualmente em solo \n"
               << "3 - N�mero de avi�es que est�o aguardando libera��o da pista e o seu tempo na fila \n"
               << "4 - N�mero de passageiros que chegaram no aeroporto e que sairam \n"
               << "5 - Relat�rio com os hor�rios de altera��o de vento e novo estado atribuido \n"
               << "6 - Relat�rio com os hor�rios onde situa��es criticas aconteceram, s�o considerados situa��es criticas: \n"
               << "  a) Avi�es aguardando maior que 5 \n"
               << "  b) Avi�es em solo maior que 70% da capacidade \n"
               << "  c) Avi�es enviados a outros aeroportos \n"
               << "  d) Solicita��es para decolagens pendentes acima de 5 \n"
               << "7 - Monitorar (Apresenta todos eventos que j� aconteceram e acompanha por 20 segundos novos eventos) \n\n"
               << "Qualquer outra op��o ir� sair do menu de relat�rios\n";
   
   std::cin >> option;
   return option;
}

int UserInterface::requestOption(const std::string& message) 
{
   int option;
   std::cout << message << std::endl;
   std::cin >> option;
   return option;
}

///////////////////////////////////////////////////////////////////////////////

void UserInterface::showMessage(const std::string& message) 
{
   std::cout << message << std::endl;
}