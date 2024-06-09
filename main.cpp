
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"

int main() {
    Node node1(1, {2, 3, 4});
    Node node2(2, {1, 3, 5});
    Player p1("yoni",1);
    std::cout << node1.isNeighbourOf(5) << std::endl;  // Output: 1 (true)

    // node1.setResource(Resource::WOOD);
    node1.placeSettlement(p1);
    // node2.placeSettlement(p1);
    std::cout << node1.getOwner().name << std::endl;
    std::cout << node2.getOwner().name << std::endl;


    // node2.placeSettlement(p1);

    node1.getOwner().addVictoryPoint();
    std::cout << node2.getOwner().getVictoryPoints() << std::endl;  // returns yoni
    std::cout << node1.getOwner().getVictoryPoints() << std::endl;  // returns yoni
    std::cout << p1.getVictoryPoints() <<std::endl;

    return 0;
}
