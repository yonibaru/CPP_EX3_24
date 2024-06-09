#include "Board.hpp"
#include <iostream>

//Node methods:
Node::Node(int num, std::initializer_list<int> neighbourList): number(num), neighbours(neighbourList),buildingType(Building::NONE),port(Port::NONE),buildingOwner(nullptr){}

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

void Node::placeSettlement(Player* p){
    if(!buildingOwner){
        buildingOwner = p;
        buildingType = Building::SETTLEMENT;
    }else{
        std::cout << "This tile is already occupied by another player!" << std::endl;
    }
}

Player* Node::getOwner() const{
    if(buildingOwner == nullptr){
        return Player(); //Returns a 'WORLD' type player AKA the NULL player.
    } else{
        return buildingOwner;
    }
}

//Tile Methods

//Everytime we want to distribute a resource after a dice roll, we just execute produceResource.
void Tile::produceResource() const{
    if(type == Resource::NONE){return;}
    for(int i = 0; i < 7;i++){
        if(this->edges[i].buildingOwner == nullptr){continue;}
        
        this->edges[i].getOwner()->addResource[type];
        if(this->edges[i].buildingType == Building::CITY){
            this->edges[i].getOwner()->addResource[type];
        }
    }
}


