
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

int main() {

    //Bunch all of this shit into a "catan" class!
    
    //These nodes would create a hexagonal graph.

                //       num  nodes_reachable
                //        |     |
                //        \/    \/
    Node* node0 = new Node(0, {1,8});
    Node* node1 = new Node(1, {0,2});
    Node* node2 = new Node(2, {1,10,3});
    Node* node3 = new Node(3, {2,4});
    Node* node4 = new Node(4,{3,5,12});
    Node* node5 = new Node(5,{4,6});
    Node* node6 = new Node(6,{5,14});
    Node* node7 = new Node(7,{8,17});
    Node* node8 = new Node(8, {0,9,7});
    Node* node9 = new Node(9, {8,10,19});
    Node* node10 = new Node(10, {2,9,11});
    Node* node11 = new Node(11,{10,12,21});
    Node* node12 = new Node(12,{4,11,13});
    Node* node13 = new Node(13, {12,14,23});
    Node* node14 = new Node(14, {6,13,15});
    Node* node15 = new Node(15, {14,25});
    Node* node16 = new Node(16, {17,27});
    Node* node17 = new Node(17, {7,16,18});
    Node* node18 = new Node(18, {17,19,29});
    Node* node19 = new Node(19, {9,18,20});
    Node* node20 = new Node(20, {19,21,31});
    Node* node21 = new Node(21, {11,20,22});
    Node* node22 = new Node(22, {21,23,33});
    Node* node23 = new Node(23, {13,22,24});
    Node* node24 = new Node(24, {23,25,35});
    Node* node25 = new Node(25, {15,24,26});
    Node* node26 = new Node(26, {25,37});
    Node* node27 = new Node(27, {16,28});
    Node* node28 = new Node(28, {27,29,38});
    Node* node29 = new Node(29, {18,28,30});
    Node* node30 = new Node(30, {29,31,40});
    Node* node31 = new Node(31, {20,30,32});
    Node* node32 = new Node(32, {31,33,42});
    Node* node33 = new Node(33, {22,32,34});
    Node* node34 = new Node(34, {33,35,44});
    Node* node35 = new Node(35, {24,34,36});
    Node* node36 = new Node(36, {35,37,46});
    Node* node37 = new Node(37, {26,36});
    Node* node38 = new Node(38, {28,39});
    Node* node39 = new Node(39, {38,40,47});
    Node* node40 = new Node(40, {30,39,41});
    Node* node41 = new Node(41, {40,42,49});
    Node* node42 = new Node(42, {32,41,43});
    Node* node43 = new Node(43, {42,44,51});
    Node* node44 = new Node(44, {34,43,45});
    Node* node45 = new Node(45, {44,53,46});
    Node* node46 = new Node(46, {36,45});
    Node* node47 = new Node(47, {39,48});
    Node* node48 = new Node(48, {47,49});
    Node* node49 = new Node(49, {41,48,50});
    Node* node50 = new Node(50, {49,51});
    Node* node51 = new Node(51, {43,50,52});
    Node* node52 = new Node(52, {51,53});
    Node* node53 = new Node(53, {45,52});


    //We can randomize the third argument (Resource) to easily create a board with randomized resources for an advanced game.
    //We'll work with the default board for now.
    Tile tile10_1(10,{node0,node1,node2,node8,node9,node10},Resource::STONE);
    Tile tile2(2,{node2,node3,node4,node10,node11,node12},Resource::WOOL);
    Tile tile9_1(9,{node4,node5,node6,node12,node13,node14},Resource::WOOD);
    Tile tile12(12,{node7,node8,node9,node17,node18,node19},Resource::WHEAT);
    Tile tile6_1(6,{node9,node10,node11,node19,node20,node21},Resource::BRICK);
    Tile tile4_1(4,{node11,node12,node13,node21,node22,node23},Resource::WOOL);
    Tile tile10_2(10,{node13,node14,node15,node23,node24,node25},Resource::BRICK);
    Tile tile9_2(9,{node16,node17,node18,node27,node28,node29},Resource::WHEAT);
    Tile tile11_1(11,{node18,node19,node20,node29,node30,node31},Resource::WOOD);
    Tile tile_7(7,{node20,node21,node22,node31,node32,node33},Resource::NONE); //DESERT???
    Tile tile3_1(3,{node22,node23,node24,node33,node34,node35},Resource::WOOD);
    Tile tile8_1(8,{node24,node25,node26,node35,node36,node37},Resource::STONE);
    Tile tile8_2(8,{node28,node29,node30,node38,node39,node40},Resource::WOOD);
    Tile tile3_2(3,{node30,node31,node32,node40,node41,node42},Resource::STONE);
    Tile tile4_2(4,{node32,node33,node34,node42,node43,node4},Resource::WHEAT);
    Tile tile5_1(5,{node34,node35,node37,node44,node45,node46},Resource::WOOL);
    Tile tile5_2(5,{node39,node40,node41,node47,node48,node49},Resource::BRICK);
    Tile tile6_2(6,{node41,node42,node43,node49,node50,node51},Resource::WHEAT);
    Tile tile11_2(11,{node43,node44,node45,node51,node52,node53},Resource::WOOL);

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
