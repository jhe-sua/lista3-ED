#include "Player.hpp"
#include <utility>
#include <string>


Player::Player()
    : id {0}
    , name {""}
    , score {0}
    , timestamp {0}
{
}

Player::Player(int id, std::string name, int score, int timestamp)
    : id {id}
    , name {std::move(name)}
    , score {score}
    , timestamp {timestamp} 
{
}

// Getters e Setters
int Player::getId() const
{
    return id;
}

std::string Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}

int Player::getTimestamp() const
{
    return timestamp;
}


void Player::setId(int id)
{
    this->id = id;
}
void Player::setName(std::string name)
{
    this->name = std::move(name);
}
void Player::setScore(int score)
{
    this->score = score;
}
void Player::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

