#include "Matchmaking.hpp"
#include <iostream>

using namespace std;

void printSeparation()
{
    cout << endl
         << "o=---=---=---=---=---=---=---=---=---=---=o"
         << endl;
}

int main()
{
    //Incialização

    // Criação de players
    Player pAna   = Player(1000, "Ana", 4730, 1);
    Player pBreno = Player(1001, "Breno", 4500, 2);
    Player pCida  = Player(1002, "Cida", 4730, 3);
    Player pDany  = Player(1003, "Dany", 4800, 4);
    Player pEnzo  = Player(1005, "Enzo", 3250, 5);
    Player pFilipe  = Player(1006, "Filipe", 3250, 6);

    // Crianção do matchmaking
    Matchmaking M = Matchmaking();

    // Testes
    cout << "Testes de implementação:" << endl;
    printSeparation();


    // Sistema vazio (Empty)
    cout << "[Teste] Print do estado vazio" << endl;
    M.printWaitingPlayers();
    printSeparation();


    // Inserindo jogadores
    M.insert(pAna);
    M.insert(pBreno);
    M.insert(pCida);
    M.insert(pDany);


    // Novo estado do sistemna
    cout << "[Teste] Print do sistema após o acréscimo de 4 jogadores" 
         << endl;
    M.printWaitingPlayers();
    printSeparation();


    // Removendo um jogador
    cout << "[Teste] Removendo um jogador" 
         << endl;

    M.removePlayer(1003);
    M.printWaitingPlayers();
    printSeparation();

    // Ordenando por IS
    cout << "[Teste] Ordenando por IS" 
         << endl;

    M.sortByScoreInsertion();
    M.printWaitingPlayers();
    printSeparation();

    // Inserindo novos jogares para teste do MS:
    cout << "Inserindo novos jogadores" 
         << endl;
    M.insert(pFilipe); M.insert(pEnzo);
    M.printWaitingPlayers();
    printSeparation();
    
    
    // Ordenando por MS
    cout << "[Teste] Ordenando por MS" 
         << endl;

    M.sortByScoreMerge();
    M.printWaitingPlayers();
    printSeparation();


    // Formando Grupos

    // Sucesso
    cout << "[Teste] Sucesso em Formação de um grupo" 
         << endl;

    int n = -1;
    Player* group = M.formGroup(3, 2000, &n);

    cout << "Grupo: " << "|";
    for(int i = 0; i < n; i++)
    {
        cout << group[i].getName() << "|";
    }
    cout << endl << "n = "<< n << endl;

    M.printWaitingPlayers(); cout << endl;
    delete[] group;

    // Fracasso
    int m = -1;
    Player* group2 = M.formGroup(4, 1000, &m);

    cout << "[Teste] Fracasso em Formação de um grupo" 
         << endl;

    cout << "Grupo 2:" <<"|";
    for(int i = 0; i < m; i++)
    {
        cout << group2[i].getName() << "|";
    }
    cout << endl << "m = "<< m << endl << endl;

    M.printWaitingPlayers();
    delete[] group2;

    // Recuperação de dados com getWainting Players


    return 0;
}