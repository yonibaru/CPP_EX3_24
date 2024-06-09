#include "Player.hpp"
#include <string>
#include <map>

Player::Player(): type(PlayerType::WORLD){}; //Empty constructor is simply the 'WORLD' player (since players are ref. we must define this )
Player::Player(std::string s,int num): name(s),number(num),type(PlayerType::PLAYER),victoryPoints(0){};
PlayerType Player::getPlayerType() const{
    return this->type;
}
int Player::getVictoryPoints() const{
    return victoryPoints;
}
void Player::addVictoryPoint(){
    victoryPoints++;
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