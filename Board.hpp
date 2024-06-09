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
class Node{

    private:
    int number;
    std::unordered_set<int> neighbours; //Neighbouring nodes, required to properly define all possible edges AKA roads.
    std::unordered_set<Resource> resources;

    public:
    Node(int num, std::initializer_list<int> neighbourList);
    void setResources(Resource r1,Resource r2, Resource r3);
    bool isNeighbourOf(int n) const;


};
class Tile{
    private:
    public:
};
class Board{
   private:
   public:
};
#endif