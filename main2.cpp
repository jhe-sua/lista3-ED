#include <iostream>
#include "Matchmaking.hpp"

using namespace std;

int main()
{
    cout << "=== INICIANDO TESTES DO MATCHMAKING ===" << endl << endl;

    Matchmaking M;

    // 1. Criação de Jogadores
    Player p1(1000, "Ana", 5, 1);
    Player p2(1001, "Bruno", 20, 2);
    Player p3(1002, "Carlo", 50, 3);
    Player p4(1003, "Dany", 100, 4);
    Player p5(1005, "Enri", 30, 5);
    Player ptutu(1007, "Tutu", 1000, 6);
    Player pangel(1006, "Angel", 1000, 7);
    Player pmaria(1009, "Maria", 980, 8);
    Player ppepe(1008, "Pepe", 100, 9); 
    Player pluiz(1009, "Luiz", 950, 10);
    Player plucas(1010, "Lucas", 20, 11);

    cout << "[TESTE] Fila Vazia Inicial:" << endl;
    M.printWaitingPlayers(); 
    cout << "---------------------------------------" << endl;

    // 2. Inserção de jogadores
    cout << "[TESTE] Inserindo Jogadores..." << endl;
    M.insert(p1); M.insert(p2); M.insert(ptutu);
    M.insert(p3); M.insert(p4); M.insert(pmaria);
    M.insert(p5);
    M.printWaitingPlayers();
    cout << "---------------------------------------" << endl;

    // 3. Remoção de jogadores
    cout << "[TESTE] Removendo Tutu e Maria..." << endl;
    M.removePlayer(ptutu.getId());
    M.removePlayer(pmaria.getId());
    M.printWaitingPlayers();
    cout << "---------------------------------------" << endl;

    // 4. Ordenação Insertion Sort
    cout << "[TESTE] Ordenacao: Insertion Sort" << endl;
    M.sortByScoreInsertion();
    M.printWaitingPlayers();
    cout << "---------------------------------------" << endl;
    
    // 5. Adicionando mais players e testando Merge Sort
    cout << "[TESTE] Inserindo Angel e Luiz + Ordenacao Merge Sort" << endl;
    M.insert(pangel);
    M.insert(pluiz);
    M.sortByScoreMerge();
    M.printWaitingPlayers();
    cout << "---------------------------------------" << endl;

    // 6. Teste de desempate (Scores Iguais)
    cout << "[TESTE] Empate de Score (Pepe/Dany e Lucas/Bruno)" << endl;
    M.insert(ppepe);
    M.insert(plucas);
    M.sortByScoreMerge(); // Ou insertion
    M.printWaitingPlayers();
    cout << "---------------------------------------" << endl;

    // 7. Formação bem-sucedida de grupo
    cout << "[TESTE] Formacao de Grupo (Sucesso)" << endl;
    int n = 0;
    Player* group = M.formGroup(4, 25, &n);

    if (group != nullptr) {
        cout << "Grupo Formado (n = " << n << "): |";
        for(int i = 0; i < n; i++) {
            cout << group[i].getName() << "|";
        }
        cout << endl;
        delete[] group; // Libera memoria do grupo
    } else {
        cout << "Nenhum grupo formado." << endl;
    }
    
    cout << "\nFila restante:" << endl;
    M.printWaitingPlayers();
    cout << "---------------------------------------" << endl;

    // 8. Tentativa de formação de grupo sem sucesso
    cout << "[TESTE] Formacao de Grupo (Falha Esperada)" << endl;
    int m = 0;
    Player* group2 = M.formGroup(4, 25, &m);

    if (group2 != nullptr) {
        cout << "Grupo Formado: |";
        for(int i = 0; i < m; i++) {
            cout << group2[i].getName() << "|";
        }
        cout << endl;
        delete[] group2;
    } else {
        cout << "Nenhum grupo formado (m = " << m << ")." << endl;
    }
    cout << "---------------------------------------" << endl;

    // 9. Recuperação dos dados (getWaitingPlayers)
    cout << "[TESTE] Recuperacao de Dados (getWaitingPlayers)" << endl;
    int k = 0;
    Player* wp = M.getWaitingPlayers(&k);

    if (wp != nullptr) {
        cout << "Waiting Players (k = " << k << "): ";
        for (int i = 0; i < k; i++) {
            cout << wp[i].getName() << (i < k - 1 ? ", " : "");
        }
        cout << endl;
        delete[] wp;
    }
    cout << "---------------------------------------" << endl;

    // 10. Limpeza Final e nova checagem
    cout << "[TESTE] Removendo demais jogadores..." << endl;
    M.removePlayer(p3.getId());
    M.removePlayer(p4.getId());
    M.removePlayer(ppepe.getId());
    M.removePlayer(pluiz.getId());
    M.removePlayer(pangel.getId());

    int l = 0;
    wp = M.getWaitingPlayers(&l);
    
    if (wp != nullptr) {
         cout << "Waiting Players Finais (l = " << l << "): ";
        for (int i = 0; i < l; i++) {
            cout << wp[i].getName() << ", ";
        }
        cout << endl;
        delete[] wp; // Liberando novamente
    } else {
        cout << "Fila Vazia ao final (l = " << l << ")." << endl;
    }

    cout << "\n=== TESTES CONCLUIDOS ===" << endl;
    return 0;
}