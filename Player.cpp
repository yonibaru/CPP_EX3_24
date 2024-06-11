#include "Player.hpp"
#include "Types.hpp"
#include <string>
#include <map>
#include <iostream>

Player::Player(): type(PlayerType::WORLD){}; //Empty constructor is simply the 'WORLD' player (since players are pointers we must define this )
Player::Player(std::string s,int num): name(s),number(num),type(PlayerType::PLAYER),victoryPoints(0){
    resourceInventory[Resource::WOOD] = 0;
    resourceInventory[Resource::STONE] = 0;
    resourceInventory[Resource::WOOL] = 0;
    resourceInventory[Resource::WHEAT] = 0;
    resourceInventory[Resource::BRICK] = 0;
};
//RESOURCE METHODS
void Player::addResource(Resource resource){
    resourceInventory[resource]++;
}
void Player::removeResource(Resource resource){
    if(resourceInventory.at(resource) <= 0){
        throw std::invalid_argument("ERROR: Player has no resources to perform 'removeResource'.");
    }
    resourceInventory[resource]--;
}

//Not sure about this....
int Player::getResourceAmount(Resource resource) const {
    return resourceInventory.at(resource);  // Returns the value associated with Resource::STONE
}



//META METHODS
std::string Player::getName() const{
    return this->name;
}
PlayerType Player::getPlayerType() const{
    return this->type;
}

//VICTORY RELATED METHODS
int Player::getVictoryPoints() const{
    return victoryPoints;
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