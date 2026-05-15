#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP
#include "Player.hpp"

const int MAX_PLAYERS = 100000;

class Matchmaking
{
private:

    Player players[MAX_PLAYERS];
    int size;

    /**
     * @brief Compara o jogador @c a com o @c b para determinar a precedência na fila.
     * 
     * @param a Jogador a ser avaliado.
     * @param b Jogador utilizado como referência de comparação.
     * 
     * @return @c true se @c a deve preceder @c b, @c false caso contrário.
     */
    bool comesFirst(Player* a, Player* b);

    /**
     * @brief Realiza um shift, deixando em sequencia todos os jogadores antes do que start e depois do que end
     */
    bool removeSortedPlayers(int start, int end);

    void merge(Player* arr, Player* aux, int start, int mid, int end);
    void mergeSort(Player* arr, Player* aux, int start, int end);
    void printPlayer(Player* a);

public:

    Matchmaking();
    ~Matchmaking() = default;

    /**
     * @brief Tenta inserir um jogador na fila de espera
     * 
     * @param player O jogador a ser inserido
     * 
     * @return @c true caso exista espaço disponivel, @c false caso não exista espaço disponivel
     */
    bool insert(Player player);

    /**
     * @brief Tenta remover da fila o jogador com o identificador informado
     * 
     * @param id ID do jogador a ser removido.
     * 
     * @return @c true caso o jogador seja encontrado e removido;
     *         @c false caso nenhum jogador com ID informado seja encontrado
     */
    bool removePlayer(int id);
    
    /**
     * @brief Ordena os jogadores por score em ordem crencente usando o algoritmo Insetion Sort
     * 
     * @details Mantem a ordem relativa de maneira cresente do timestamp caso dois jogadores tenham o mesmo score
     */
    void sortByScoreInsertion();

    /**
     * @brief Ordena os jogadores por score em ordem crencente usando o algoritmo Merge Sort
     * 
     * @details Mantem a ordem relativa de maneira cresente do timestamp caso dois jogadores tenham o mesmo score
     */
    void sortByScoreMerge();
    
    /**
     * @brief Tenta formar um grupo de jogadores com base na proximidade de scores.
     * 
     * @details Percorre a lista de jogadores buscando uma sequência de tamanho groupSize
     * onde a diferença entre o maior e o menor score seja menor ou igual ao delta.
     * 
     * @note Esta função pressupõe que o array interno de jogadores já está ordenado por score.
     * 
     * @param groupSize A quantidade exata de jogadores desejada para o grupo.
     * @param delta A tolerância máxima de diferença de score permitida entre os membros.
     * @param[out] n Ponteiro que receberá o tamanho do grupo retornado (groupSize) ou 0 em caso de falha.
     * 
     * @return Player* Ponteiro para um novo array alocado dinamicamente contendo os jogadores. 
     *         Retorna @c nullptr se nenhum grupo válido for encontrado.
     * @warning O chamador é responsável por liberar a memória retornada usando @c delete[].
     */
    Player* formGroup(int groupSize, int delta, int* n);

    /**
     * @brief Retorna os jogadores e o numero de jogadores que estão atualmente na fila.
     * 
     * @param[out] n Ponteiro que recebera a quantidade de jogadores retornados.
     * 
     * @return Player* Ponteiro para um novo array alocado dinamicamente contendo os jogadores.
     *         Retorna @c nullptr se não existem jogadores na fila de espera.
     * 
     * @warning O chamador é responsável por liberar a memória retornada usando @c delete[].
     */
    Player* getWaitingPlayers(int* n);

    /**
     * @brief exibe o formato atual da fila de espera
     */
    void printWaitingPlayers();

};
#endif
