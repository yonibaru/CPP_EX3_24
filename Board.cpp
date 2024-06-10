#include "Board.hpp"
#include "Types.hpp"
#include <iostream>

//Node methods:
Node::Node(int number_arg, std::initializer_list<int> neighbours_arg): number(number_arg), neighbours(neighbours_arg),buildingType(Building::NONE),port(Port::NONE),buildingOwner(nullptr){}

bool Node::isNeighbourOf(int n) const {
    return this->neighbours.find(n) != neighbours.end();
}

// Any building placed on this node will earn resources according to the values stored in 'resources'
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
    return buildingOwner; //returns a nullptr if theres no owner (for now.)
}

Building Node::getBuildingType() const{
    return buildingType;
}

//Tile Methods

Tile::Tile(int number_arg, std::initializer_list<Node*> edges_arg, Resource type_arg): number(number_arg),type(type_arg),edges(edges_arg) {
    if(edges.size() != 6){throw std::invalid_argument("Tiles must be of size 6!");}
    for (auto edge : this->edges) {
        edge->setResource(type);
    }
}

//Everytime we want to distribute a resource after a dice roll, we just execute produceResource.
void Tile::produceResource() const{
    if(type == Resource::NONE){return;}
    for (auto edge : this->edges) {
        if(edge->getOwner() == nullptr){continue;}
        edge->getOwner()->addResource(this->type);
        if(edge->getBuildingType() == Building::CITY){
            edge->getOwner()->addResource(this->type);
        }
    }
}


