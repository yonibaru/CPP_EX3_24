#include "Board.hpp"
#include <iostream>

//Node methods:
Player world;
Node::Node(int num, std::initializer_list<int> neighbourList): number(num), neighbours(neighbourList),buildingType(Building::NONE),port(Port::NONE),buildingOwner(world){}

bool Node::isNeighbourOf(int n) const {
    return this->neighbours.find(n) != neighbours.end();
}

// Any building placed on this node will earn resources according to the values stored in 'resources'
// Might be useless?
void Node::setResource(Resource r = Resource::NONE){
    if(r != Resource::NONE && this->resources.size() < 3){
        this->resources.insert(r);
    }
}

void Node::placeSettlement(Player& p){
    if(buildingOwner.getPlayerType() == PlayerType::WORLD){
        buildingOwner = p;
        buildingType = Building::SETTLEMENT;
    }else{
        std::cout << "This tile is already occupied by another player!" << std::endl;
    }
}

Player& Node::getOwner(){
    return buildingOwner;
}

//Tile Methods

// void Tile::produceResource() const{
//     for(int i = 0; i < 7;i++){
//         this->edges[i].
//     }
// }


