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
   std::cout   << "--- Menu de relatórios --- \n"
               << "Escolha a opção de relatório abaixo pelo seu respectivo index \n\n"
               << "1 - Número de aviões pousados até o momento \n"
               << "2 - Número de aviões atualmente em solo \n"
               << "3 - Número de aviões que estão aguardando liberação da pista e o seu tempo na fila \n"
               << "4 - Número de passageiros que chegaram no aeroporto e que sairam \n"
               << "5 - Relatório com os horários de alteração de vento e novo estado atribuido \n"
               << "6 - Relatório com os horários onde situações criticas aconteceram, são considerados situações criticas: \n"
               << "  a) Aviões aguardando maior que 5 \n"
               << "  b) Aviões em solo maior que 70% da capacidade \n"
               << "  c) Aviões enviados a outros aeroportos \n"
               << "  d) Solicitações para decolagens pendentes acima de 5 \n"
               << "7 - Monitorar (Apresenta todos eventos que já aconteceram e acompanha por 20 segundos novos eventos) \n\n"
               << "Qualquer outra opção irá sair do menu de relatórios\n";
   
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