#ifndef BOARD_HPP
#define BOARD_HPP
#include "Player.hpp"
#include <unordered_set>
#include <initializer_list>

enum class Resource{
    WOOD,
    STONE,
    WOOL,
    WHEAT,
    BRICK,
    NONE,
};

enum class Building{
    SETTLEMENT,
    CITY,
    NONE,
};

enum class Port{
    GENEREAL_PORT, //3:1 PORT
    WOOD_PORT,     //2:1 WHEAT PORT
    STONE_PORT,    //2:1 STONE PORT
    WOOL_PORT,     //2:1 WOOL PORT
    WHEAT_PORT,    //2:1 WHEAT PORT
    BRICK_PORT,    //2:1 BRICK PORT
    NONE,
};

enum class TileType{
    FOREST,
    HILLS,
    PASTURE_LAND,
    MOUNTAINS,
    AGRICULTURAL_LAND,
    DESERT,
};

class Node{

    private:
    int number;
    std::unordered_set<int> neighbours; //Neighbouring nodes, required to properly define all possible edges AKA roads.
    std::unordered_set<Resource> resources;
    Building buildingType;
    Port port;
    Player& buildingOwner;

    public:
    Node(int num, std::initializer_list<int> neighbourList);
    void setResource(Resource r);
    bool isNeighbourOf(int n) const;
    void placeSettlement(Player p);
    void placeCity();
    Player& getOwner();
};
class Tile{

    private:
    int number;
    TileType type;
    Node edges[6];
    bool isRobbed;

    public:
    void produceResource() const;
};
class Board{
   private:
   Node nodes[56];
   public:
   Node returnNode(int num) const;
};
#endif