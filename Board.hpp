#ifndef BOARD_HPP
#define BOARD_HPP
#include "Player.hpp"
#include "Types.hpp"
#include <unordered_set>
#include <initializer_list>
#include <memory>
#include <set>

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
    void placeCity();
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
   std::vector<Player*> players;
   public:
   Catan(Player* p1,Player* p2,Player* p3);
   Node* returnNode(int num) const;
   void deleteBoard();
   void rollNumber() const;
   Player* getCurrentPlayer() const;
};
#endif