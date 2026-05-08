#include <iostream>
#include "Player.hpp"

using namespace std;


// Usamos uma lista de inicialização
// Usamos move 
Player::Player(int id, string name, int score, int timestamp)
    : id {id}
    , name {move(name)}
    , score {score}
    , timestamp {timestamp} 
{
}

// Getters e Setters

// id
int Player::GetId() const
{
    return id;
}
std::string Player::GetName() const
{
    return name;
}
int Player::GetScore() const
{
    return score;
}
int Player::GetTimestamp() const
{
    return timestamp;
}


void Player::SetId(int id)
{
    this->id = id;
}
void Player::SetName(std::string name)
{
    this->name = name;
}
void Player::SetScore(int score)
{
    this->score = score;
}
void Player::SetTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

