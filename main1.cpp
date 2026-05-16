#include <iostream>
#include "Matchmaking.hpp"

using namespace std;

int main()
{
    // Criação de Jogadores
    //[id | nome | score | timestamp]
    
    
    Player ptutu = Player(1007, "Tutu", 1000, 6);
    Player pangel = Player(1006, "Angel", 1000, 7);
    Player pmaria = Player(1009, "Maria", 980, 8);
    Player ppepe = Player(1008, "Pepe", 100, 9); 
    Player pluiz = Player(1009, "Luiz", 950, 10);
    Player plucas = Player(1010, "Lucas", 20, 11);

    // Criação de Matchmaking


    // Estado atual do sistema
    M.printWaitingPlayers(); cout << endl;

    // inserção de jogadores
    bool out1 = M.insert(p1);
    bool out2 = M.insert(p2);

    bool out6 = M.insert(ptutu); // a ser removido

    bool out3 = M.insert(p3);
    bool out4 = M.insert(p4);

    bool out7 = M.insert(pmaria); // a ser removida

    bool out5 = M.insert(p5);

    
    cout << out1 << " | "
         << out2 << " | "
         << out3 << " | "
         << out4 << " | "
         << out5 << " | "
         << out6 << " | "
         << out7 << endl;

    M.printWaitingPlayers(); cout << endl;

    // remoção de jogadores
    M.removePlayer(ptutu.getId());
    M.removePlayer(pmaria.getId());

    M.printWaitingPlayers(); cout << endl;

    // ordenação utilizando insertion sort
    cout << "By Insertion" << endl;
    M.sortByScoreInsertion();
    M.printWaitingPlayers(); cout << endl;
    
    // adicionando mais players scores diferentes
    bool out9 = M.insert(pangel);
    bool out8 = M.insert(pluiz);
    M.printWaitingPlayers(); cout << endl;

    // ordenação utilizando merge sort;
    cout << "By Merge" << endl;
    M.sortByScoreMerge();
    M.printWaitingPlayers();
    cout << endl;

    // adicionando pepe que tem mesmo score que Dany
    bool out10 = M.insert(ppepe);
    M.printWaitingPlayers(); cout << endl;

    // ordenação com empate de score insertion
    cout << "By Insertion" << endl;
    M.sortByScoreInsertion();
    M.printWaitingPlayers(); cout << endl;

    // adicionando lucas que tem mesmo score que Bruno
    bool out11 = M.insert(plucas);
    M.printWaitingPlayers(); cout << endl;

    // ordenação com empate de score insertion
    cout << "By Merge" << endl;
    M.sortByScoreMerge();
    M.printWaitingPlayers(); cout << endl;
    

    // formação bem-sucedida de grupo
    int n = -1;
    Player* group = M.formGroup(4, 25, &n);

    cout << "Grupo:" <<"|";
    for(int i = 0; i < n; i++)
    {
        cout << group[i].getName() << "|";
    }
    cout << endl << "n = "<< n << endl << endl;

    M.printWaitingPlayers(); cout << endl;
    delete[] group;

    // tentativa de formação de grupo sem sucesso;
    int m = -1;
    Player* group2 = M.formGroup(4, 25, &m);

    cout << "Grupo 2:" <<"|";
    for(int i = 0; i < m; i++)
    {
        cout << group2[i].getName() << "|";
    }
    cout << endl << "m = "<< m << endl << endl;

    M.printWaitingPlayers();
    delete[] group2;

    //recuperação dos dados por meio do método getWaitingPlayers;

    int k = -1;
    Player* wp = M.getWaitingPlayers(&k);

    cout << "Waiting Players: ";
    for (int i = 0; i < k; i++)
    {
        cout << wp[i].getName() << ", ";
    }
    cout << endl << "k = " << k << endl << endl;

    delete[] wp;

    
    //deletando todos
    
    M.removePlayer(p3.getId());
    M.removePlayer(p4.getId());
    M.removePlayer(ppepe.getId());
    M.removePlayer(pluiz.getId());
    M.removePlayer(pangel.getId());

    //recuperação dos dados por meio do método getWaitingPlayers;

    int l = -1;
    wp = M.getWaitingPlayers(&l);

    cout << "Waiting Players: ";
    for (int i = 0; i < l; i++)
    {
        cout << wp[i].getName() << ", ";
    }
    cout << endl << "l = " << l << endl << endl;

    return 0;
}