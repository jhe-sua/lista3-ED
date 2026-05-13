#include "Matchmaking.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>

Matchmaking::Matchmaking()
    : size {0}
{
}

bool Matchmaking::insert(Player player)
{
    if(size == MAX_PLAYERS)
        return false;

    players[size - 1] = player;
    return true;
}

// Há forma melhor de fazer?
bool Matchmaking::removePlayer(int id)
{
    // Verificando o último
    if(players[size - 1].getId() == id)
    {
        size--;
        return true;
    }

    int index = 0;
    while(index < (size - 1))
    {
        if(players[index].getId() == id)
        {
            for(int j = index; j < (size - 1); j++)
            {
                players[j] = players[j + 1];
            }
            
            size--;
        }

        index++;
    }
    
    return false;
}

void Matchmaking::sortByScoreInsertion()
{
    int i, j, current;
    for (i = 1; i < size; i++)
    {
        current = players[i].getScore();
        j = i - 1;

        // Ordem crescente de score (e em empates, de timestamp)
        while (j >= 0 && players[j].getScore() > current)
        {
            players[j+1] = players[j];
            j = j - 1;
        }
        players[j + 1] = current;
    }
}

bool Matchmaking::comesFirst(Player* a, Player* b)
{
    if((*a).getScore() != (*b).getScore())
        return (*a).getScore() < (*b).getScore();

    return (*a).getTimestamp() < (*b).getTimestamp();
        
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
    if(start == end) //(>=)?
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

bool removeSortedPlayers(int start, int end)
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
/*
Waiting Players:
[1 | Ana   | 1000 | 1]
[2 | Bruno | 1100 | 2]

[id | nome | score | timestamp]
*/

void Matchmaking::printPlayer(Player* a)
{
    cout << "[" 
         << std::left << std::setw(2) << (*a).getId() << "| "
         << std::left << std::setw(5) << (*a).getName() << " | "
         << std::left << std::setw(4) << (*a).getScore() << " | "
         << std::right << (*a).getTimestamp()
         << "]" << endl;
}



void Matchmaking::printWaitingPlayers()
{
    cout << "Waiting Players:" << endl;
    if(size <= 0)
    {
        cout << "(empty)" << endl;
        return;
    }

    for(int j = 0; j < size; j++)
    {
        printPlayer(&player[i]);
    }

    return;
}

