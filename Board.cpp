#include "Board.hpp"

//Node methods:

Node::Node(int num, std::initializer_list<int> neighbourList) : number(num), neighbours(neighbourList) {}
bool Node::isNeighbourOf(int n) const {
    return this->neighbours.find(n) != neighbours.end();
}
void Node::addResource(Resource r = Resource::NONE){
    if(r != Resource::NONE && this->resources.size() < 3){
        this->resources.insert(r);
    }
}


