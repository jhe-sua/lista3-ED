#include "Matchmaking.hpp"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;


// 1. Gerar players (dados pseudoaleatórios)
// 2. Gerar os dois Matchmakings(?)
// 3. Inserir players
// 4. Para diferentes tamanhos de entrada, obter o tempo médio de cada 
// algoritmo de ordenção em 5 repetições para entradas semelhantes.
// n = 10
// n = 100
// n = 1000
// n = 5000
// n = 10000
// n = 50000
// n = 100000


// 1. Gerar players (dados pseudoaleatórios)

const int MAX_PLAYERS = 100000;

void playersGenerator(Player* players, int maxPlayers, int maxScore)
{
    // Semente fixa para resultados reproduzíveis
    mt19937 randomGen(123456);
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


void insertNPlayers(Matchmaking* M, Player* players, int N)
{
    for(int i = 0; i < N; i++)
    {
        M->insert(players[i]);
    }
}

void averageTime(Matchmaking* M, int repetitions, int numberOfPlayers){}



// n = 100
// n = 1000
// n = 5000
// n = 10000
// n = 50000
// n = 100000
/*

MODELO DE USO:

#include <chrono>
#include <iostream>

template <typename Func>
long long medirTempoMicrosegundos(Func&& f)
{
    using clock = std::chrono::steady_clock;

    auto start = clock::now();
    f();
    auto end = clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

*/
int main()
{
    // quero guardar os resultados e printar os resultados
    // Inicialização
    int testCases[7] = {10, 100, 1000, 5000, 10'000, 50'000, 100'000};
    int repetitions = 5;
    Matchmaking IS = Matchmaking();
    Matchmaking MS = Matchmaking();

    long long timeIS[7];
    long long timeMS[7];

    //Obtendo a média dos tempos
    for(int i = 0; i < 7; i++)
    {
        int n = testCases[i];
        Player* playersBase = new Player[n];

        long long resultIS = 0;

        for(int j = 0; j < repetitions; j++)
        {
            // Gerando e inserindo Players
            playersGenerator(playersBase, n, 5000);
            insertNPlayers(&IS, playersBase, n);

            // Calculando o tempo
            auto start = steady_clock::now();
            IS.sortByScoreInsertion();
            auto end = steady_clock::now();
            auto dur = end - start;

            // Guardando o resultado e resetando
            resultIS += duration_cast<microseconds>(dur).count();
            IS.resetMatchmaking();
        }

        timeIS[i] = resultIS / repetitions;

        delete[] playersBase;
    }

    return 0;
}

/*
Esse código tem alguns problemas, o último que estudei rapidamente antes de 
meu tempo acabar está no gerador de players. Com um seed fixa ele gera
sempre os mesmos players, é preciso mudar isso.

Esboço de solução do chat:

void playersGenerator(Player* players, int maxPlayers, int maxScore, std::mt19937& randomGen)
{
    std::uniform_int_distribution<int> dist(0, maxScore);

    for(int i = 0; i < maxPlayers; i++)
    {
        int id = i + 1;
        int timestamp = i + 1;
        std::string name = "Player" + std::to_string(i + 1);
        int score = dist(randomGen);

        players[i] = Player(id, name, score, timestamp);
    }
}

no main:
std::mt19937 randomGen(123456);

na chamada:
playersGenerator(playersBase, n, 5000, randomGen);


aparentemente o problema está no gerador ser criado dentro da função, por
por isso precisamos cria-lo no main. Se entender o q isso quer dizer, me 
fala.
*/