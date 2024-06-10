
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

int main() {

    Player* p1 = new Player("yoni",1);
    Player* p2 = new Player("rob",2);
    Catan board;
    

    //p1 places 2 settlements on node 0 and node 1
    // node0->placeSettlement(p1);
    // node1->placeSettlement(p1);    
    
    // tile1.produceResource();
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
