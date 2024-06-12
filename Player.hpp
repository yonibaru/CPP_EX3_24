#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Types.hpp"
#include <string>
#include <map>

class Player{

    private:
    std::string name;
    PlayerType type;
    int victoryPoints;
    std::map<Resource,int> resourceInventory;
    int buildingCount;
    int roadCount;
    
    public:
    Player();
    Player(std::string s,int num);
    //RESOURCE METHODS
    void addResource(Resource resource);
    void removeResource(Resource resource);
    int getResourceAmount(Resource resource) const;
    //META METHODS
    PlayerType getPlayerType() const;
    std::string getName() const;
    int getBuildingCount() const;
    void incrementBuildingCount();
    void getRoadCount() const;
    void incrementRoadCount();
    //VICTORY RELATED METHODS
    int getVictoryPoints() const;
    void addVictoryPoint();
    void removeVictoryPoint();
    
};

#endif