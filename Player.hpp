#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Types.hpp"
#include <string>
#include <map>

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
    void addResource(Resource resource);
    void removeResource(Resource resource);
    int getStoneAmount() const;
    //META METHODS
    PlayerType getPlayerType() const;
    std::string getName() const;
    //VICTORY RELATED METHODS
    int getVictoryPoints() const;
    void addVictoryPoint();
    void removeVictoryPoint();
    
};

#endif