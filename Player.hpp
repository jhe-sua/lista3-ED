#ifndef PLAYER
#define PLAYER

#include <iostream>

class Player
{
private:
    int id;
    std::string name;
    int score;
    int timestamp;

public:
    Player();
    Player(
        int id,
        std::string name,
        int score,
        int timestamp
    );
    ~Player() = default;

    int GetId() const;
    std::string GetName() const;
    int GetScore() const;
    int GetTimestamp() const;

    void SetId(int id);
    void SetName(std::string name);
    void SetScore(int score);
    void SetTimestamp(int timestamp);

};

#endif