#include "Matchmaking.hpp"
#include <iostream>
#include <iomanip>

Matchmaking::Matchmaking()
    : size {0}
{
}


bool Matchmaking::insert(Player player)
{
    if(size >= MAX_PLAYERS || size < 0)
        return false;

    players[size] = player;
    size++;
    return true;
}


bool Matchmaking::removePlayer(int id)
{
    if(size <= 0)
        return false;

    // Verificando o último
    if(players[size - 1].getId() == id)
    {
        size--;
        return true;
    }


    for(int index = 0; index < size; index++)
    {
        if(players[index].getId() == id)
        {
            for(int j = index; j < size - 1; j++)
            {
                players[j] = players[j + 1];
            }
            size--;
            return true;
        }
    }
    
    return false;
}


bool Matchmaking::comesFirst(Player* a, Player* b)
{
    if((*a).getScore() != (*b).getScore())
        return (*a).getScore() < (*b).getScore();

    return (*a).getTimestamp() < (*b).getTimestamp();
        
}


void Matchmaking::sortByScoreInsertion()
{
    for(int i = 1; i < size; i++)
    {
        Player current = players[i];
        int j = i - 1;

        // Ordem crescente de score (e em empates, de timestamp)
        while (j >= 0 && comesFirst( &current, &players[j]))
        {
            players[j+1] = players[j];
            j = j - 1;
        }
        players[j + 1] = current;
    }
}


void Matchmaking::merge(Player* arr, Player* aux, int start, int mid, int end)
{
    int i = start, k = start, j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(comesFirst(&arr[i], &arr[j]))
        {
            aux[k] = arr[i];
            i++;
            k++;
        } else {
            aux[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        aux[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end) 
    {
        aux[k] = arr[j];
        j++;
        k++;
    }

    // Atualizando arr
    int l = start;
    while(l <= end)
    {
        arr[l] = aux[l];
        l++;
    }
}


void Matchmaking::mergeSort(Player* arr, Player* aux, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int mid = (start + end)/2;
    mergeSort(arr, aux, start, mid);
    mergeSort(arr, aux, mid + 1, end);
    
    merge(arr, aux, start, mid, end);
}


void Matchmaking::sortByScoreMerge()
{
    if(size <= 0)
        return;

    Player* aux = new Player[size];

    int start = 0, end = size - 1;
    mergeSort(players, aux, start, end);
    delete[] aux;
}


bool Matchmaking::removeSortedPlayers(int start, int end)
{
    // Partindo do presuposto de que players já está ordenado
    if(start > end)
        return false;

    if(end > size - 1)
        return false;
    
    int s = start, i = end + 1;

    while(i < size)
    {
        players[s] = players[i];
        s++;
        i++;
    }

    size -= end - start + 1;
    return true;
}


Player* Matchmaking::formGroup(int groupSize, int delta, int* n)
{ 
    // Partindo do presuposto que players já está ordenado
    if(size <= 0)
        return nullptr;

    if(n == nullptr)
        return nullptr;

    if(groupSize <= 0 || delta < 0)
    {
        *n = 0;
        return nullptr;
    }

    int start = 0, end = groupSize - 1;
    while(end < size)
    {
        if(delta >= (players[end].getScore() - players[start].getScore()))
        {
            Player* group = new Player[groupSize];
            // Compondo group
            for(int i = 0; i < groupSize; i++)
            {
                group[i] = players[start + i];
            }
            removeSortedPlayers(start, end);
            *n = groupSize;
            return group;
        }
        start++;
        end++;
    }

    *n = 0;
    return nullptr;
}


Player* Matchmaking::getWaitingPlayers(int* n)
{
    if(n == nullptr)
        return nullptr;

    if(size <= 0)
    {
        *n = 0;
        return nullptr;
    }

    Player* waitingPlayers = new Player[size];
    for(int i = 0; i < size; i++)
    {
        waitingPlayers[i] = players[i];
    }
    
    *n = size;
    return waitingPlayers;
}


void Matchmaking::printPlayer(Player* a)
{
    std::cout << "[" 
              << std::left << std::setw(2) << (*a).getId() << "| "
              << std::left << std::setw(5) << (*a).getName() << " | "
              << std::left << std::setw(4) << (*a).getScore() << " | "
              << std::right << (*a).getTimestamp()
              << "]" << std::endl;
}


void Matchmaking::printWaitingPlayers()
{
    std::cout << "Waiting Players:" << std::endl;
    if(size <= 0)
    {
        std::cout << "(empty)" << std::endl;
        return;
    }

    for(int j = 0; j < size; j++)
    {
        printPlayer(&players[j]);
    }

    return;
}