#include "Matchmaking.hpp"
#include <iostream>

using namespace std;

void printSeparation()
{
    cout << endl
         << "|---o---o---o---o---o---o---o---o---o---|"
         << endl;
}

int main()
{
    //Incialização

    // Criação de players
    Player p1 = Player(1000, "Ana", 5000, 1);
    Player p2 = Player(1001, "Breno", 4500, 2);
    Player p3 = Player(1002, "Cida", 4730, 3);
    Player p4 = Player(1003, "Dany", 4800, 4);
    Player p5 = Player(1005, "Enzo", 3250, 5);

    // Crianção do matchmaking
    Matchmaking M = Matchmaking();

    // Testes
    cout << "Testes de implementação"
    printSeparation();

    // Sistema vazio (Empty)
    M.printWaitingPlayers();

    


    return 0;
}