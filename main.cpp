
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

int main() {
    //These nodes would create a hexagonal graph.

    //       num  nodes_reachable
    //        |     |
    //        \/    \/
    Node* node0 = new Node(0, {1,2});
    Node* node1 = new Node(1, {0,2});
    Node* node2 = new Node(2, {1,10});
    Node* node8 = new Node(8, {0,9});
    Node* node9 = new Node(9, {8,10});
    Node* node10 =  new Node(10, {2,9});

    //We can randomize the third argument (Resource) to easily create a board with randomized resources.
    Tile tile10_1(10,{node0,node1,node2,node8,node9,node10},Resource::STONE);
    Tile tile2(10,{node0,node1,node2,node8,node9,node10},Resource::WOOL);
    Tile tile9_1(10,{node0,node1,node2,node8,node9,node10},Resource::WOOD);
    Tile tile12(10,{node0,node1,node2,node8,node9,node10},Resource::WHEAT);
    Tile tile6_1(10,{node0,node1,node2,node8,node9,node10},Resource::BRICK);
    Tile tile4_1(10,{node0,node1,node2,node8,node9,node10},Resource::WOOL);
    Tile tile10_2(10,{node0,node1,node2,node8,node9,node10},Resource::BRICK);
    Tile tile9_2(10,{node0,node1,node2,node8,node9,node10},Resource::WHEAT);
    Tile tile11_1(10,{node0,node1,node2,node8,node9,node10},Resource::WOOD);
    Tile tile_7(7,{node0,node1,node2,node8,node9,node10},Resource::NONE); //DESERT???
    Tile tile3_1(10,{node0,node1,node2,node8,node9,node10},Resource::WOOD);
    Tile tile8_1(10,{node0,node1,node2,node8,node9,node10},Resource::STONE);
    Tile tile8_2(10,{node0,node1,node2,node8,node9,node10},Resource::WOOD);
    Tile tile3_2(10,{node0,node1,node2,node8,node9,node10},Resource::STONE);
    Tile tile4_2(10,{node0,node1,node2,node8,node9,node10},Resource::WHEAT);
    Tile tile5_1(10,{node0,node1,node2,node8,node9,node10},Resource::WOOL);
    Tile tile5_2(10,{node0,node1,node2,node8,node9,node10},Resource::BRICK);
    Tile tile6_2(10,{node0,node1,node2,node8,node9,node10},Resource::WHEAT);
    Tile tile11_2(10,{node0,node1,node2,node8,node9,node10},Resource::WOOL);

    Player* p1 = new Player("yoni",1);
    Player* p2 = new Player("rob",2);

    //p1 places 2 settlements on node 0 and node 1
    node0->placeSettlement(p1);
    node1->placeSettlement(p1);    
    
    tile1.produceResource();
    std::cout << p1->getStoneAmount() << std::endl;
    // node2.placeSettlement(p1);

    // node1.getOwner()->addVictoryPoint();
    // p1->addVictoryPoint();
    // std::cout << node2.getOwner()->getVictoryPoints() << std::endl;  // returns yoni
    // std::cout << node1.getOwner()->getVictoryPoints() << std::endl;  // returns yoni
    // std::cout << p1->getVictoryPoints() <<std::endl;

    //Add a cleanup function for our players and nodes
    delete p1;
    delete p2;

    return 0;
}
