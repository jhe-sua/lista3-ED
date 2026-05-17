#include "Matchmaking.hpp"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
Comando para compilação:
g++ performanceTest.cpp Matchmaking.cpp Player.cpp -o performanceTest
*/
void PlayersGenerator(Player* players, int maxPlayers, int maxScore, mt19937& randomGen)
{
    uniform_int_distribution<int> dist(0, maxScore);

    for(int i = 0; i < maxPlayers; i++)
    {
        int id = i + 1;
        int timestamp = i + 1;
        string name = "Player" + to_string(i + 1);
        int score = dist(randomGen);

        players[i] = Player(id, name, score, timestamp);
    }
}


void InsertPlayers(Matchmaking* M, Player* players, int N)
{
    for(int i = 0; i < N; i++)
    {
        M->insert(players[i]);
    }
}


int main()
{
    // quero guardar os resultados e printar os resultados
    // Inicialização
    int numberOfTests = 7;
    int testCases[7] = {10, 100, 1000, 5000, 10'000, 50'000, 100'000};
    int repetitions = 5;
    Matchmaking* M = new Matchmaking();
    mt19937 randomGen(123456);

    long long timeIS[numberOfTests];
    long long timeMS[numberOfTests];


    //Obtendo a média dos tempos
    for(int i = 0; i < numberOfTests; i++)
    {
        int n = testCases[i];
        Player* playersBase = new Player[n];

        long long resultIS = 0;
        long long resultMS = 0;

        for(int j = 0; j < repetitions; j++)
        {
            // Gerando e inserindo Players
            PlayersGenerator(playersBase, n, 5000, randomGen);
            InsertPlayers(M, playersBase, n);

            // Insertion sort
            // Calculando o tempo
            auto start = steady_clock::now();
            M->sortByScoreInsertion();
            auto end = steady_clock::now();
            auto durIS = end - start;

            // Guardando o resultado e resetando
            resultIS += duration_cast<microseconds>(durIS).count();

            M->resetMatchmaking();
            InsertPlayers(M, playersBase, n);

            // Merge Sort
            // Calculando o tempo
            start = steady_clock::now();
            M->sortByScoreMerge();
            end = steady_clock::now();
            auto durMS = end - start;

            // Guardando o resultado e resetando
            resultMS += duration_cast<microseconds>(durMS).count();
            M->resetMatchmaking();
        }

        timeIS[i] = resultIS / repetitions;
        timeMS[i] = resultMS / repetitions;

        delete[] playersBase;
    }

    // Printagem
    cout <<  "| " << "Tamanho da entrada (n)" 
         << " | " << "Tempo médio MS - O(nlog(n))" 
         << " | " << "Tempo médio IS - O(n²)" 
         << " |"  << endl;

    for(int k = 0; k < numberOfTests; k++)
    {
        long long x = testCases[k];

        cout <<  "| " << testCases[k] 
             << " | " << timeMS[k] 
             << " | " << timeIS[k]
             << " |"  << endl;
    }

    delete M;


    return 0;
}
