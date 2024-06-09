#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
enum class PlayerType{
    PLAYER,
    WORLD
};

class Player{
    private:
    int number;
    PlayerType type;
    int victoryPoints;
    public:
    std::string name;
    Player();
    Player(std::string s,int num);
    PlayerType getPlayerType() const;
    int getVictoryPoints() const;
    void addVictoryPoint();
};

#endif