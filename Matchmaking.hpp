#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP
#include "Player.hpp"

const int MAX_PLAYERS = 100000;

class Matchmaking
{
private:

    Player players[MAX_PLAYERS];
    int size;

    bool comesFirst(Player* a, Player* b);
    bool removeSortedPlayers(int start, int end);

    void merge(Player* arr, Player* aux, int start, int mid, int end);
    void mergeSort(Player* arr, Player* aux, int start, int end);
    void printPlayer(Player* a);

public:

    Matchmaking();
    ~Matchmaking() = default;

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

};
#endif
