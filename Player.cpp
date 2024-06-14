#include "Player.hpp"
#include "Types.hpp"
#include <string>
#include <map>
#include <iostream>

Player::Player(): type(PlayerType::WORLD){}; //Empty constructor is simply the 'WORLD' player (since players are pointers we must define this )
Player::Player(std::string s): name(s),type(PlayerType::PLAYER),victoryPoints(0){
    resourceInventory[Resource::WOOD] = 0;
    resourceInventory[Resource::STONE] = 0;
    resourceInventory[Resource::WOOL] = 0;
    resourceInventory[Resource::WHEAT] = 0;
    resourceInventory[Resource::BRICK] = 0;
    devCardInventory[DevCardType::KNIGHT] = 0;
    devCardInventory[DevCardType::ROAD_BUILDING] = 0;
    devCardInventory[DevCardType::YEAR_OF_PLENTY] = 0;
    devCardInventory[DevCardType::MONOPOLY] = 0;
    devCardInventory[DevCardType::VICTORY_POINT] = 0;
    buildingCount = 0;
    roadCount = 0;
    biggestArmy = false;
};
//RESOURCE METHODS
void Player::addResource(Resource resource){
    resourceInventory[resource]++;
}
void Player::removeResource(Resource resource){
    if(resourceInventory.at(resource) <= 0){
        throw std::invalid_argument("ERROR: Player has no resources to perform 'removeResource()'.");
    }
    resourceInventory[resource]--;
}

void Player::printResources() const{
    std::cout << this->name << "'s Inventory:\n";
    std::cout << "WOOD: " << resourceInventory.at(Resource::WOOD) << "\n";
    std::cout << "STONE: " << resourceInventory.at(Resource::STONE) << "\n";
    std::cout << "WOOL: " << resourceInventory.at(Resource::WOOL) << "\n";
    std::cout << "WHEAT: " << resourceInventory.at(Resource::WHEAT) << "\n";
    std::cout << "BRICK: " << resourceInventory.at(Resource::BRICK) << "\n";
}
int Player::getResourceAmount(Resource resource) const {
    return resourceInventory.at(resource);  // Returns the value associated with Resource::STONE
}

void Player::addDevCard(DevCardType card){
    devCardInventory[card]++;
}

void Player::removeDevCard(DevCardType card){
    if(devCardInventory.at(card) <= 0){
        throw std::invalid_argument("ERROR: Player has insufficent card amount to perform 'removeDevCard()'.");
    }
    devCardInventory[card]--;
}

int Player::getDevCardAmount(DevCardType card) const{
    return devCardInventory.at(card);
}

void Player::incrementBuildingCount(){
    this->buildingCount++;
}

void Player::incrementRoadCount(){
    this->roadCount++;
}


//META METHODS
std::string Player::getName() const{
    return this->name;
}
PlayerType Player::getPlayerType() const{
    return this->type;
}

int Player::getBuildingCount() const{
    return this->buildingCount;
}

int Player::getRoadCount() const{
    return this->roadCount;
}

//VICTORY RELATED METHODS
int Player::getVictoryPoints() const{
    int actualVictoryPoints = victoryPoints + getDevCardAmount(DevCardType::VICTORY_POINT); 
    return actualVictoryPoints;
}
void Player::addVictoryPoint(){
    victoryPoints++;
}

void Player::removeVictoryPoint(){
    victoryPoints--; //If you've lost Longest path card / Biggest army card.
}




// class Player{
//     private:
//     std::string name;
//     std::map<std::string, int> resources;
//     int settlements;
//     int cities;
//     int roads;
//     public:
//     // Constructor
//     // ! ...

//     void rollDice(){
    
//     }

//     void placeSettlement(){

//     }

//     void placeRoad(){
//         //Check if there is an existing road
//         //if not place it
//     }

//     void buyDevelopmentCard(){

//     }

//     void printPoints(){

//     }

    //    void isWinner(){
    //     //CHECK WHETHER THIS PLAYER HAS 10 POINTS, IF SO SET SOME FLAG THAT DECLARES THERE IS A WINNER.
    //     //EACH PLAYER AT HIS TURN WILL CHECK WHETHER HE IS A WINNER WHEN APPENDING 'WINNER POINTS' AND THEY REACH 10!
    //    }

// };