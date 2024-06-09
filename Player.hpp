#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Board.hpp"
#include <string>
#include <map>
enum class PlayerType{
    PLAYER,
    WORLD
};



class Player{

    private:
    std::string name;
    int number;
    PlayerType type;
    int victoryPoints;
    std::map<Resource,int> resourceInventory;
    public:
    Player();
    Player(std::string s,int num);
    //RESOURCE METHODS
    void addResource();
    void removeResource();
    //META METHODS
    PlayerType getPlayerType() const;
    std::string getName() const;
    //VICTORY RELATED METHODS
    int getVictoryPoints() const;
    void addVictoryPoint();
    
};

#endif