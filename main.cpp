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

    // Cabeçalho
    cout << "Testes de implementação:" << endl;
    printSeparation();



// Testes de sistema em estado vazio

    cout << "[Teste] Print do estado vazio" << endl << endl;
    M.printWaitingPlayers();

    cout << endl << endl
         << "[Teste] Removendo e tentando formar grupos em estado vazio"
         << endl << endl;
    bool out1 = M.removePlayer(pAna.getId());
    int g = -1;
    Player* group = M.formGroup(3, 2000, &g);
    cout << "Remoção realizada: " << out1 << " (Player não encontrado)"
         << endl
         << "Endereço do grupo formado: " << group << endl
         << "Tamanho do grupo formado: g = " << g << endl; 

    printSeparation();


    
// Testes de sistema com players

    cout << "[Teste] Estado do sistema após o acréscimo de 4 jogadores" 
         << endl;

    // Inserindo jogadores
    M.insert(pAna);
    M.insert(pBreno);
    M.insert(pCida);
    M.insert(pDany);

    M.printWaitingPlayers();
    cout << endl << endl;

    // Removendo um jogador
    cout << "[Teste] Removendo um jogador" 
         << endl
         << "Removendo Dany (Retorno true)" << endl;

    bool dany = M.removePlayer(pDany.getId());
    M.printWaitingPlayers();

    cout << endl << "Remoção realizada: " << dany << endl << endl
         << "Removendo um player inexistente - Filipe (Retorno false)" 
         << endl;

    bool filipe = M.removePlayer(pFilipe.getId());
    M.printWaitingPlayers();
    cout << endl << "Remoção realizada: " << filipe << endl;
    printSeparation();

// Testes de ordenação
    // Ordenando por IS
    cout << "[Teste] Ordenando por IS" 
         << endl;

    M.sortByScoreInsertion();
    M.printWaitingPlayers();

    // Inserindo novos jogares para teste do MS:
    cout << endl << endl
         << "Inserindo novos jogadores" 
         << endl;
    M.insert(pFilipe); M.insert(pEnzo);
    M.printWaitingPlayers();
    
    // Ordenando por MS
    cout << endl << endl
         << "[Teste] Ordenando por MS" 
         << endl;

    M.sortByScoreMerge();
    M.printWaitingPlayers();
    printSeparation();

// Testes de formação de Grupos

    // Sucesso
    cout << "[Teste] Sucesso em Formação de um grupo" 
         << endl;

    int n = -1;
    Player* group1 = M.formGroup(3, 2000, &n);

    cout << "Grupo: " << "|";
    for(int i = 0; i < n; i++)
    {
        cout << group1[i].getName() << "|";
    }
    cout << endl << "n = "<< n << endl;

    M.printWaitingPlayers(); cout << endl;

    if(group1 != nullptr) delete[] group1;

    // Fracasso
    int m = -1;
    Player* group2 = M.formGroup(4, 1000, &m);

    cout << "[Teste] Fracasso em Formação de um grupo" 
         << endl;

    cout << "Grupo 2:";
    for(int i = 0; i < m; i++)
    {
        cout << group2[i].getName() << "|";
    }
    cout << endl << "m = "<< m << endl;

    M.printWaitingPlayers();
    if(group2 != nullptr) delete[] group2;
    printSeparation();

// Recuperação dos dados por meio do método getWaitingPlayers;
    cout << "[Teste] Guardando o estado do sistema com getWaitingPlayers" 
         << endl << endl;
    int k = -1;
    cout << "Estado Atual:" << endl;
    M.printWaitingPlayers();
    Player* wp = M.getWaitingPlayers(&k);

    cout << endl << "Após resetar o array de players:" << endl;
    M.resetMatchmaking();
    M.printWaitingPlayers();
    
    cout << endl << "[getWatingPlayers]" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << wp[i].getName() << ", ";
    }
    if(wp != nullptr) delete[] wp;

    cout << endl << "k = " << k << endl << endl
         << "Estado foi guardado em getWatingPlayers";
    printSeparation();
    
    
    return 0;
}