
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"

int main() {
    Node node1(1, {2, 3, 4});
    Node node2(2, {1, 3, 5});
    Player* p1 = new Player("yoni",1);
    Player* p2 = new Player("rob",2);

    // node1.setResource(Resource::WOOD);
    node1.placeSettlement(p1);
    node1.placeSettlement(p2);
    // std::cout << node2.getOwner()->name << std::endl;


    // node2.placeSettlement(p1);

    // node1.getOwner()->addVictoryPoint();
    // p1->addVictoryPoint();
    // std::cout << node2.getOwner()->getVictoryPoints() << std::endl;  // returns yoni
    // std::cout << node1.getOwner()->getVictoryPoints() << std::endl;  // returns yoni
    // std::cout << p1->getVictoryPoints() <<std::endl;

    //Add a cleanup function for our players
    delete p1;
    delete p2;

    return 0;
}
