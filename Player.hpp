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
    std::map<DevCardType,int> devCardInventory;
    int buildingCount;
    int roadCount;
    
    public:
    Player();
    Player(std::string s);
    bool biggestArmy;

    //RESOURCE METHODS
    void addResource(Resource resource);
    void removeResource(Resource resource);
    int getResourceAmount(Resource resource) const;

    void addDevCard(DevCardType card);
    void removeDevCard(DevCardType card);
    int getDevCardAmount(DevCardType card) const;

    void printResources() const;
    //META METHODS
    PlayerType getPlayerType() const;
    std::string getName() const;
    int getBuildingCount() const;
    void incrementBuildingCount();
    int getRoadCount() const;
    void incrementRoadCount();
    //VICTORY RELATED METHODS
    int getVictoryPoints() const;
    void addVictoryPoint();
    void removeVictoryPoint();
    
};

#endif