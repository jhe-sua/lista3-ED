#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP
#include "Player.hpp"

const int MAX_PLAYERS = 100000;

class Matchmaking
{
private:

    Player players[MAX_PLAYERS];
    int size;

public:

    Matchmaking();
    ~Matchmaking() = default;

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    // Privar essas funções
    Player* merge(Player* arr1,int n1, Player* arr2, int n2);
    Player* mergeSortAuxiliar(Player* arr, int n);
    // To achando isso bem feio, a função não é tecnicamente recursiva
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    // Outros métodos auxiliares, se necessário
};
#endif
