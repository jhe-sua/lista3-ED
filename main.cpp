#include <iostream>
#include "Matchmaking.hpp"

int main()
{
    //[id | nome | score | timestamp]

    // Criação de Players
    Player p1 = Player(1000, "Ana", 5, 1);
    Player p2 = Player(1001, "Bruno", 20, 2);
    Player p3 = Player(1002, "Carlos", 50, 3);
    Player p4 = Player(1003, "Danyel", 100, 4);
    Player p5 = Player(1005, "Enri", 30, 5);

    // Crianção do matchmaking
    Matchmaking M = Matchmaking();


    // Estado atual do sistema
    M.printWaitingPlayers();
    std::cout << std::endl;

    // Testes de métodos que deveriam "falhar" com size == 0

    // Inserindo Players
    bool out1 = M.insert(p1);
    bool out2 = M.insert(p2);
    bool out3 = M.insert(p3);
    bool out4 = M.insert(p4);
    bool out5 = M.insert(p5);

    std::cout << out1 << " | "
              << out2 << " | "
              << out3 << " | "
              << out4 << " | "
              << out5 <<std::endl;

    M.printWaitingPlayers();
    std::cout << std::endl;


    // Ordenação por ambos os métodos
    std::cout << "By Insertion" << std::endl;
    M.sortByScoreInsertion();
    M.printWaitingPlayers();
    std::cout << std::endl;
    
    std::cout << "By Merge" << std::endl;
    M.sortByScoreMerge();
    M.printWaitingPlayers(); // Deveria permanecer ordenado
    std::cout << std::endl;

    // Formando um grupo
    int n = 0;
    Player* group = M.formGroup(2, 10, &n);

    std::cout << "|";
    for(int i = 0; i < n; i++)
    {
        std::cout << group[i].getName() << "|";
    }
    std::cout << std::endl;

    M.printWaitingPlayers();
    delete[] group;

    return 0;
}