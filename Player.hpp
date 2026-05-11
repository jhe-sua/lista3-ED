#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

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

    int getId() const;
    std::string getName() const;
    int getScore() const;
    int getTimestamp() const;

    void setId(int id);
    void setName(std::string name);
    void setScore(int score);
    void setTimestamp(int timestamp);

};

#endif