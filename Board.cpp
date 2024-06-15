#include "Board.hpp"
#include "Types.hpp"
#include <iostream>
#include <random>
#include <algorithm>

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
        p->incrementBuildingCount();
        p->addVictoryPoint();
    }else{
        std::cout << "This tile is already occupied by another player!" << std::endl;
    }
}

void Node::placeCity(Player* p){
    if(buildingOwner == p && buildingType == Building::SETTLEMENT){
        buildingType = Building::CITY;
        p->addVictoryPoint();
    }
}

Player* Node::getOwner() const{
    return this->buildingOwner; //returns a nullptr if theres no owner (for now.)
}

Building Node::getBuildingType() const{
    return this->buildingType;
}

std::unordered_set<int> Node::getNeighbours() const{
    return this->neighbours;
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

//Catan Methods
Catan::Catan(Player* p1,Player* p2,Player* p3): currentPlayerTurn(p1) {

    //Initialize nodes
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
    //You have to do it this way. Sorry.
    nodes[0] = node0;
    nodes[1] = node1;
    nodes[2] = node2;
    nodes[3] = node3;
    nodes[4] = node4;
    nodes[5] = node5;
    nodes[6] = node6;
    nodes[7] = node7;
    nodes[8] = node8;
    nodes[9] = node9;
    nodes[10] = node10;
    nodes[11] = node11;
    nodes[12] = node12;
    nodes[13] = node13;
    nodes[14] = node14;
    nodes[15] = node15;
    nodes[16] = node16;
    nodes[17] = node17;
    nodes[18] = node18;
    nodes[19] = node19;
    nodes[20] = node20;
    nodes[21] = node21;
    nodes[22] = node22;
    nodes[23] = node23;
    nodes[24] = node24;
    nodes[25] = node25;
    nodes[26] = node26;
    nodes[27] = node27;
    nodes[28] = node28;
    nodes[29] = node29;
    nodes[30] = node30;
    nodes[31] = node31;
    nodes[32] = node32;
    nodes[33] = node33;
    nodes[34] = node34;
    nodes[35] = node35;
    nodes[36] = node36;
    nodes[37] = node37;
    nodes[38] = node38;
    nodes[39] = node39;
    nodes[40] = node40;
    nodes[41] = node41;
    nodes[42] = node42;
    nodes[43] = node43;
    nodes[44] = node44;
    nodes[45] = node45;
    nodes[46] = node46;
    nodes[47] = node47;
    nodes[48] = node48;
    nodes[49] = node49;
    nodes[50] = node50;
    nodes[51] = node51;
    nodes[52] = node52;
    nodes[53] = node53;

    //We can randomize the third argument (Resource) to easily create a board with randomized resources for an advanced game.
    //We'll work with the default board for now.
    Tile* tile10_1 = new Tile(10,{node0,node1,node2,node8,node9,node10},Resource::STONE);
    Tile* tile2 = new Tile(2,{node2,node3,node4,node10,node11,node12},Resource::WOOL);
    Tile* tile9_1 = new Tile(9,{node4,node5,node6,node12,node13,node14},Resource::WOOD);
    Tile* tile12 = new Tile(12,{node7,node8,node9,node17,node18,node19},Resource::WHEAT);
    Tile* tile6_1 = new Tile(6,{node9,node10,node11,node19,node20,node21},Resource::BRICK);
    Tile* tile4_1 = new Tile(4,{node11,node12,node13,node21,node22,node23},Resource::WOOL);
    Tile* tile10_2 = new Tile(10,{node13,node14,node15,node23,node24,node25},Resource::BRICK);
    Tile* tile9_2 = new Tile(9,{node16,node17,node18,node27,node28,node29},Resource::WHEAT);
    Tile* tile11_1 = new Tile(11,{node18,node19,node20,node29,node30,node31},Resource::WOOD);
    Tile* tile7 = new Tile(7,{node20,node21,node22,node31,node32,node33},Resource::NONE); //DESERT???
    Tile* tile3_1 = new Tile(3,{node22,node23,node24,node33,node34,node35},Resource::WOOD);
    Tile* tile8_1 = new Tile(8,{node24,node25,node26,node35,node36,node37},Resource::STONE);
    Tile* tile8_2 = new Tile(8,{node28,node29,node30,node38,node39,node40},Resource::WOOD);
    Tile* tile3_2 = new Tile(3,{node30,node31,node32,node40,node41,node42},Resource::STONE);
    Tile* tile4_2 = new Tile(4,{node32,node33,node34,node42,node43,node44},Resource::WHEAT);
    Tile* tile5_1 = new Tile(5,{node34,node35,node36,node44,node45,node46},Resource::WOOL);
    Tile* tile5_2 = new Tile(5,{node39,node40,node41,node47,node48,node49},Resource::BRICK);
    Tile* tile6_2 = new Tile(6,{node41,node42,node43,node49,node50,node51},Resource::WHEAT);
    Tile* tile11_2 = new Tile(11,{node43,node44,node45,node51,node52,node53},Resource::WOOL);

    //Initialize tiles
    tiles[0][0] = nullptr;
    tiles[0][1] = nullptr;
    tiles[1][0] = nullptr;
    tiles[1][1] = nullptr;
    tiles[2][0] = tile2;
    tiles[2][1] = nullptr;
    tiles[3][0] = tile3_1;
    tiles[3][1] = tile3_2;
    tiles[4][0] = tile4_1;
    tiles[4][1] = tile4_2;
    tiles[5][0] = tile5_1;
    tiles[5][1] = tile5_2;
    tiles[6][0] = tile6_1;
    tiles[6][1] = tile6_2;
    tiles[7][0] = tile7;
    tiles[7][1] = nullptr;
    tiles[8][0] = tile8_1;
    tiles[8][1] = tile8_2;
    tiles[9][0] = tile9_1;
    tiles[9][1] = tile9_2;
    tiles[10][0] = tile10_1;
    tiles[10][1] = tile10_2;
    tiles[11][0] = tile11_1;
    tiles[11][1] = tile11_2;
    tiles[12][0] = tile12;
    tiles[12][1] = nullptr;

    //Initialize roads
    for (int i = 0; i < 54; ++i) {
        for (int j = 0; j < 54; ++j) {
            roads[i][j] = -1;
        }
    }
    // Initialize Development Cards
    for (int i = 0; i < 14; ++i) {
        deck.push_back(DevCardType::KNIGHT);
    }
    for (int i = 0; i < 2; ++i) {
        deck.push_back(DevCardType::ROAD_BUILDING);
    }
    for (int i = 0; i < 2; ++i) {
        deck.push_back(DevCardType::YEAR_OF_PLENTY);
    }
    for (int i = 0; i < 2; ++i) {
        deck.push_back(DevCardType::MONOPOLY);
    }
    for (int i = 0; i < 5; ++i) {
        deck.push_back(DevCardType::VICTORY_POINT);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);

    turnCount = 0;
    currentPlayerIndex = 0;
    currentBiggestArmyHolder = nullptr;
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    std::cout << "It's now " << currentPlayerTurn->getName() << "'s turn." << std::endl;

}

void Catan::deleteBoard(){
    for(int i = 0; i < 54; i++) {
        delete nodes[i];
    }
    for(int i = 0; i < 12; i++) {
        delete tiles[i][0];
        delete tiles[i][1];
    }
}

void Catan::rollDice() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6);
    int dice1 = distribution(gen);
    int dice2 = distribution(gen);
    int sum = dice1 + dice2;
    std::cout << getCurrentPlayer()->getName() << " rolls the dice and gets: " << sum << std::endl;

    // if 7 is rolled do x.....
    if(sum == 7){
        std::cout << "SPECIAL CASE: 7 WAS ROLLED! Robber HAS to be moved and no player shall any gain resources." << sum << std::endl;
        //If we wanted to expand this into the full version of Catan, we would create a rolledSeven() function which would prompt to move the robber.
    
        return;
    }

    if(tiles[sum][0] != nullptr){
        tiles[sum][0]->produceResource();
    }
    if(tiles[sum][1] != nullptr){
        tiles[sum][1]->produceResource();
    }
}

void Catan::endTurn(){
    std::cout << currentPlayerTurn->getName() << " ends his turn." << std::endl;
    std::cout << "---" << std::endl;
    checkBiggestArmyCard();
    turnCount = (turnCount + 1) % players.size();
    currentPlayerIndex = turnCount;
    currentPlayerTurn = players[turnCount];
    std::cout << "It's now " << currentPlayerTurn->getName() << "'s turn." << std::endl;
}

//This function allows the current player to place a road between 2 nodes.
void Catan::placeRoad(int node1,int node2) {

    //Check if currentPlayer has sufficient resources for that road
    if(currentPlayerTurn->getResourceAmount(Resource::BRICK) < 1 || currentPlayerTurn->getResourceAmount(Resource::WOOD)){
        return;
    }
    //Check if a road could even be placed between the two nodes.
    if(nodes[node1]->isNeighbourOf(node2) == 0 || nodes[node2]->isNeighbourOf(node1) == 0){
        return; 
    }
    //Check if there's no existing road there.
    if(roads[node1][node2] != -1 || roads[node2][node1] != -1) {
        return;
    }

    //Check if either node has a settlement belonging to the current player
    //(Otherwise he shouldn't be able to place one there.)
    if(nodes[node1]->getOwner() == currentPlayerTurn || nodes[node2]->getOwner() == currentPlayerTurn){
        roads[node1][node2] = currentPlayerIndex;
        roads[node2][node1] = currentPlayerIndex; 
        currentPlayerTurn->removeResource(Resource::WOOD);
        currentPlayerTurn->removeResource(Resource::BRICK);
        currentPlayerTurn->incrementRoadCount();
        std::cout << getCurrentPlayer()->getName() << " places a road between nodes " << node1 << " and " << node2 << "." << std::endl;
        return;
    }

    // If we reached here it means:
    // 1. A road could be placed between the two nodes.
    // 2. Player has the sufficient resources to build the road
    // 3. Theres no existing road road there
    // 4. He doesn't have nearby owned settlements.
    // All that's left is to check whether theres a player-owned road connecting
    // to one of the nodes.

    for (const auto& element : nodes[node1]->getNeighbours()) {
        if(roads[node1][element] == currentPlayerIndex && roads[element][node1] == currentPlayerIndex){
            roads[node1][node2] = currentPlayerIndex;
            roads[node2][node1] = currentPlayerIndex; 
            currentPlayerTurn->removeResource(Resource::WOOD);
            currentPlayerTurn->removeResource(Resource::BRICK);
            currentPlayerTurn->incrementRoadCount();
            std::cout << getCurrentPlayer()->getName() << " places a road between nodes " << node1 << " and " << node2 << "." << std::endl;
            return;
        }
    }

    for (const auto& element : nodes[node2]->getNeighbours()) {
        if(roads[node2][element] == currentPlayerIndex && roads[element][node2] == currentPlayerIndex){
            roads[node1][node2] = currentPlayerIndex;
            roads[node2][node1] = currentPlayerIndex; 
            currentPlayerTurn->removeResource(Resource::WOOD);
            currentPlayerTurn->removeResource(Resource::BRICK);
            currentPlayerTurn->incrementRoadCount();
            std::cout << getCurrentPlayer()->getName() << " places a road between nodes " << node1 << " and " << node2 << "." << std::endl;
            return;
        }
    }
}


void Catan::placeFreeRoad(Player* p,int node1,int node2) {
    if(p->getRoadCount() >= 2){
        std::cout << "1" << std::endl;
        return;
    }
    //Check if a road could even be placed between the two nodes.
    if(nodes[node1]->isNeighbourOf(node2) == 0 || nodes[node2]->isNeighbourOf(node1) == 0){
        std::cout << "2" << std::endl;
        return; 
    }
    //Check if there's no existing road there.
    if(roads[node1][node2] != -1 || roads[node2][node1] != -1) {
        std::cout << "3" << std::endl;
        return;
    }

    //Check if either node has a settlement belonging to the current player
    //(Otherwise he shouldn't be able to place one there.)
    if(nodes[node1]->getOwner() == p || nodes[node2]->getOwner() == p){
        roads[node1][node2] = getPlayerIndex(p);
        roads[node2][node1] = getPlayerIndex(p); 
        p->incrementRoadCount();
        std::cout << players[getPlayerIndex(p)]->getName() << " places a road between nodes " << node1 << " and " << node2 << "." << std::endl;
        return;
    }

    // If we reached here it means:
    // 1. A road could be placed between the two nodes.
    // 3. Theres no existing road road there
    // 4. He doesn't have nearby owned settlements.
    // All that's left is to check whether theres a player-owned road connecting
    // to one of the nodes.

    for (const auto& element : nodes[node1]->getNeighbours()) {
        if(roads[node1][element] == getPlayerIndex(p) && roads[element][node1] == getPlayerIndex(p)){
            roads[node1][node2] = getPlayerIndex(p);
            roads[node2][node1] = getPlayerIndex(p);  
            std::cout << players[getPlayerIndex(p)]->getName() << " places a road between nodes " << node1 << " and " << node2 << "." << std::endl;
            p->incrementRoadCount();
            return;
        }
    }

    for (const auto& element : nodes[node2]->getNeighbours()) {
        if(roads[node2][element] == getPlayerIndex(p) && roads[element][node2] == getPlayerIndex(p)){
            roads[node1][node2] = getPlayerIndex(p);
            roads[node2][node1] = getPlayerIndex(p); 
            std::cout << getCurrentPlayer()->getName() << " places a road between nodes " << node1 << " and " << node2 << "." << std::endl;
            p->incrementRoadCount();
            return;
        }
    }
    std::cout << "4" << std::endl;
}

bool Catan::canBuildRoad(int node1,int node2){

    //Check if a road could even be placed between the two nodes.
    if(nodes[node1]->isNeighbourOf(node2) == 0 || nodes[node2]->isNeighbourOf(node1) == 0){
        return false;
    }
    //Check if there's no existing road there.
    if(roads[node1][node2] != -1 || roads[node2][node1] != -1) {
        return false;
    }

    //Check if either node has a settlement belonging to the current player
    //(Otherwise he shouldn't be able to place one there.)
    if(nodes[node1]->getOwner() == currentPlayerTurn || nodes[node2]->getOwner() == currentPlayerTurn){
        return true;
    }

    // If we reached here it means:
    // 1. A road could be placed between the two nodes.
    // 2. Player has the sufficient resources to build the road
    // 3. Theres no existing road road there
    // 4. He doesn't have nearby owned settlements.
    // All that's left is to check whether theres a player-owned road connecting
    // to one of the nodes.

    for (const auto& element : nodes[node1]->getNeighbours()) {
        if(roads[node1][element] == currentPlayerIndex && roads[element][node1] == currentPlayerIndex){
            return true;
        }
    }
    for (const auto& element : nodes[node2]->getNeighbours()) {
        if(roads[node2][element] == currentPlayerIndex && roads[element][node2] == currentPlayerIndex){
            return true;
        }
    }
}
//This can be used by any player at the start of the game to place 2 free settlements anywhere on the board.
void Catan::placeFreeSettlement(Player* p, int node){
    //Check if there's an existing building on that node.
    if(nodes[node]->getBuildingType() != Building::NONE){
        return;
    }

    //Check if there are any settlements on the nearby nodes
    for(const auto& element: nodes[node]->getNeighbours()){
        if(nodes[element]->getBuildingType() != Building::NONE){
            return;
        }
    }
    //The first two settlements are free and can be placed on any node (assuming its empty)
    if(p->getBuildingCount() < 2){
        nodes[node]->placeSettlement(p);
        std::cout << players[getPlayerIndex(p)]->getName() << " placed a settlement in node " << node <<"." << std::endl;
    }
}

//Turn-specific function, allows the player of the current turn to place a settlement.
void Catan::placeSettlement(int node){
    //Check if there's an existing building on that node.
    if(nodes[node]->getBuildingType() != Building::NONE){
        return;
    }
    //Check if there are any settlements on the nearby nodes
    for(const auto& element: nodes[node]->getNeighbours()){
        if(nodes[element]->getBuildingType() != Building::NONE){
            return;
        }
    }
    //Check if he has the resources
    if(currentPlayerTurn->getResourceAmount(Resource::WOOD) < 1 || currentPlayerTurn->getResourceAmount(Resource::WHEAT) < 1 || currentPlayerTurn->getResourceAmount(Resource::BRICK) < 1 || currentPlayerTurn->getResourceAmount(Resource::WOOL) < 1){
        return;
    }
    //Check if theres atleast one friendly road connecting to this node and if so, let the player place the road.
    for (const auto& element : nodes[node]->getNeighbours()) {
        if(roads[node][element] == currentPlayerIndex && roads[element][node] == currentPlayerIndex){
            nodes[node]->placeSettlement(currentPlayerTurn);
            currentPlayerTurn->removeResource(Resource::WOOD);
            currentPlayerTurn->removeResource(Resource::BRICK);
            currentPlayerTurn->removeResource(Resource::WOOL);
            currentPlayerTurn->removeResource(Resource::WHEAT);
            std::cout << getCurrentPlayer()->getName() << " placed a settlement in node " << node <<"." << std::endl;
            return;
        }
    }
}


void Catan::upgradeSettlement(int node){
    //Check if that node is not empty
    if(nodes[node]->getBuildingType() != Building::SETTLEMENT){
        return;
    }
    //Check if it is owned by the current player
    if(nodes[node]->getOwner() != currentPlayerTurn){
        return;
    }
    //Check if he has the sufficient resource to upgrade
    if(currentPlayerTurn->getResourceAmount(Resource::STONE) < 3 || currentPlayerTurn->getResourceAmount(Resource::WHEAT) < 2){
        return;
    }
    currentPlayerTurn->removeResource(Resource::STONE);
    currentPlayerTurn->removeResource(Resource::STONE);
    currentPlayerTurn->removeResource(Resource::STONE);
    currentPlayerTurn->removeResource(Resource::WHEAT);
    currentPlayerTurn->removeResource(Resource::WHEAT);
    nodes[node]->placeCity(currentPlayerTurn);
    std::cout << getCurrentPlayer()->getName() << " upgraded a settlement to a city at node " << node <<"." << std::endl;
}

void Catan::buyDevelopmentCard(){
    if (deck.empty()) {
        throw std::out_of_range("The deck is empty");
    }
    if(currentPlayerTurn->getResourceAmount(Resource::WHEAT) < 1  || currentPlayerTurn->getResourceAmount(Resource::STONE) < 1 || currentPlayerTurn-> getResourceAmount(Resource::WOOL) < 1){
        return;
    }
    currentPlayerTurn->removeResource(Resource::WHEAT);
    currentPlayerTurn->removeResource(Resource::WOOL);
    currentPlayerTurn->removeResource(Resource::STONE);
    DevCardType drawnCard = deck.back();
    currentPlayerTurn->addDevCard(drawnCard);
    deck.pop_back();
    std::cout << getCurrentPlayer()->getName() << " bought a development card. " << std::endl;
}

void Catan::useMonopolyCard(Resource resource){
    //Doesn't have that card.
    if(currentPlayerTurn->getDevCardAmount(DevCardType::MONOPOLY) < 1){
        return;
    }
    for(auto p:this->players){
        if(p != this->currentPlayerTurn){
            int amount = p->getResourceAmount(resource);
            for(int i = 0; i < amount; i++){
                p->removeResource(resource);
                currentPlayerTurn->addResource(resource);
            }
        }
    }
    currentPlayerTurn->removeDevCard(DevCardType::MONOPOLY);
}

void Catan::useYearOfPlentyCard(Resource resource1,Resource resource2){
    //Doesn't have that card.
    if(currentPlayerTurn->getDevCardAmount(DevCardType::YEAR_OF_PLENTY) < 1){
        return;
    }
    currentPlayerTurn->addResource(resource1);
    currentPlayerTurn->addResource(resource2);
    currentPlayerTurn->removeDevCard(DevCardType::YEAR_OF_PLENTY);
}

void Catan::useRoadBuildingCard(int node1, int node2, int node3, int node4){
    //Doesn't have that card.
    if(currentPlayerTurn->getDevCardAmount(DevCardType::ROAD_BUILDING) < 1){
        return;
    }
    if(canBuildRoad(node1,node2) && canBuildRoad(node3,node4)){
        currentPlayerTurn->addResource(Resource::BRICK);
        currentPlayerTurn->addResource(Resource::BRICK);
        currentPlayerTurn->addResource(Resource::WOOD);
        currentPlayerTurn->addResource(Resource::WOOD);
        placeRoad(node1,node2);
        placeRoad(node3,node4);
        currentPlayerTurn->removeDevCard(DevCardType::ROAD_BUILDING);
    } 
}

void Catan::tradeResource(Player* p, Resource resource1, int amount1, Resource resource2, int amount2){
    if(p == currentPlayerTurn){
        return;
    }
    if(currentPlayerTurn->getResourceAmount(resource1) < amount1 || currentPlayerTurn->getResourceAmount(resource2) < amount2){
        return;
    }
    
    for(int i = 0; i < amount1; i++){
        currentPlayerTurn->removeResource(resource1);
        p->addResource(resource1);
    }
    for(int j = 0; j < amount2;j++){
        p->removeResource(resource2);
        currentPlayerTurn->addResource(resource2);
    }
}

void Catan::tradeDevCards(Player* p,DevCardType card1,int amount1,DevCardType card2,int amount2){
    if(p == currentPlayerTurn){
        return;
    }
    if(currentPlayerTurn->getDevCardAmount(card1) < amount1 || currentPlayerTurn->getDevCardAmount(card2) < amount2){
        return;
    }
    
    for(int i = 0; i < amount1; i++){
        currentPlayerTurn->removeDevCard(card1);
        p->addDevCard(card1);
    }
    for(int j = 0; j < amount2;j++){
        p->removeDevCard(card2);
        currentPlayerTurn->addDevCard(card2);
    }
}

Player* Catan::getCurrentPlayer() const{
    return currentPlayerTurn;
}

int Catan::getPlayerIndex(Player* p) const{
    auto it = std::find(players.begin(), players.end(), p);
    if (it != players.end()) {
        return std::distance(players.begin(), it);
    } else {
        return -1;
    }
}

void Catan::checkBiggestArmyCard(){
    int biggestArmyAmount = 0;
    for(auto p:this->players){
        if(p->biggestArmy == true){
            p->removeVictoryPoint();
            p->removeVictoryPoint();
        }
        p->biggestArmy = false;
    }
    Player* currentPlayerWithBiggestArmy = nullptr;
    for(auto p: this->players){
        if(p->getDevCardAmount(DevCardType::KNIGHT) > biggestArmyAmount && biggestArmyAmount >= 3){
            currentPlayerWithBiggestArmy = p;
        }
    }
    if(currentPlayerWithBiggestArmy == nullptr){
        return; //There are no players with the largest army.
    }
    for(auto p:this->players){
        if(currentPlayerWithBiggestArmy->getDevCardAmount(DevCardType::KNIGHT) == p->getDevCardAmount(DevCardType::KNIGHT) && p != currentPlayerWithBiggestArmy){
            return; //Two players have the same amount of knights.
        }
    }
    currentPlayerWithBiggestArmy->biggestArmy = true;
    currentPlayerWithBiggestArmy->addVictoryPoint();
    currentPlayerWithBiggestArmy->addVictoryPoint();
    if(currentBiggestArmyHolder != currentPlayerWithBiggestArmy){
        std::cout << currentPlayerWithBiggestArmy->getName() << " has the biggest army now and receives 2 victory points!" << std::endl;
    }
    currentBiggestArmyHolder = currentPlayerWithBiggestArmy;
}

void Catan::checkWinner() const{
    for(auto p: this->players){
        if(p->getVictoryPoints() >= 10){
            std::cout << p->getName() << " is the winner!" << std::endl;
        }
    }
}

