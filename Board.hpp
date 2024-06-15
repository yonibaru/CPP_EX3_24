#ifndef BOARD_HPP
#define BOARD_HPP
#include "Player.hpp"
#include "Types.hpp"
#include <unordered_set>
#include <initializer_list>
#include <memory>
#include <set>
#include <vector>

class Node{
    private:
    int number;
    std::unordered_set<int> neighbours; //Neighbouring nodes, required to properly define all possible edges AKA roads.
    std::unordered_set<Resource> resources;
    Building buildingType;
    Port port;
    Player* buildingOwner; //Each node with a building holds a pointer to its owner.
    
    public:
    Node(int number_arg, std::initializer_list<int> neighbours_arg);
    void setResource(Resource r);
    bool isNeighbourOf(int n) const;
    void placeSettlement(Player* p);
    void placeCity(Player* p);
    std::unordered_set<int> getNeighbours() const;
    Player* getOwner() const;
    Building getBuildingType() const;
};
class Tile{

    private:
    int number;
    Resource type;
    std::unordered_set<Node*> edges;
    bool isRobbed;

    public:
    Tile(int number_arg, std::initializer_list<Node*> edges_arg,Resource type_arg);
    void produceResource() const;
};
class Catan{

   private:
   Node* nodes[54];
   Tile* tiles[13][2];
   int roads[54][54]; //Represents all possible connections 
   std::vector<Player*> players;
   int turnCount;
   int currentPlayerIndex;
   Player* currentPlayerTurn;
   std::vector<DevCardType> deck;
   Player* currentBiggestArmyHolder;
   public:
   Catan(Player* p1,Player* p2,Player* p3);
   void placeRoad(int node1,int node2);
   void placeSettlement(int node);
   void placeFreeSettlement(Player* p, int node);
   void placeFreeRoad(Player* p,int node1,int node2);
   bool canBuildRoad(int node1, int node2);
   void upgradeSettlement(int node);
   void buyDevelopmentCard();
   void useYearOfPlentyCard(Resource resource1,Resource resource2);
   void useRoadBuildingCard(int node1,int node2,int node3,int node4);
   void useMonopolyCard(Resource resource);
   void tradeResource(Player* p, Resource resource1, int amount1, Resource resource2, int amount2);
//    void tradeCards(p1,p2,)
   void endTurn();
   void deleteBoard();
   void rollDice() const;
   Player* getCurrentPlayer() const;
   int getPlayerIndex(Player* p) const;
   void checkWinner() const;
   void checkBiggestArmyCard();
};
#endif