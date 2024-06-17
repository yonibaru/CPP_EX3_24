#include <cassert>
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

void testBoardPlacements() {
    // Create players
    Player* p1 = new Player("Michael");
    Player* p2 = new Player("Robert");
    Player* p3 = new Player("Edward");


    // Initialize game
    Catan game(p1, p2, p3);

    // Place initial free settlements and roads for setup
    game.placeFreeSettlement(p1, 0);
    game.placeFreeSettlement(p2, 2);
    game.placeFreeSettlement(p3, 4);
    game.placeFreeSettlement(p1, 16);
    game.placeFreeSettlement(p2, 9);
    game.placeFreeSettlement(p3, 11);

    game.placeFreeRoad(p1, 0, 8);
    game.placeFreeRoad(p1, 7, 8);

    game.placeFreeRoad(p2, 2, 10);
    game.placeFreeRoad(p2, 10, 9);

    game.placeFreeRoad(p3, 4, 12);
    game.placeFreeRoad(p3, 11, 12);
    
    //It's p1's turn.


    //Trying to upgrade a city with insufficient resources.
    try {
        game.upgradeSettlement(0);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    //Trying to place a road with insufficient resources.
    try {
        game.placeRoad(16,17);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    //Trying to place a settlement with insufficient resources.
    try {
        game.placeSettlement(7);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        game.buyDevelopmentCard();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    for(int i = 0; i < 5; i++){
        p1->addResource(Resource::WOOD);
        p1->addResource(Resource::WOOL);
        p1->addResource(Resource::BRICK);
        p1->addResource(Resource::STONE);
        p1->addResource(Resource::WHEAT);

        p2->addResource(Resource::WOOD);
        p2->addResource(Resource::WOOL);
        p2->addResource(Resource::BRICK);
        p2->addResource(Resource::STONE);
        p2->addResource(Resource::WHEAT);

        p3->addResource(Resource::WOOD);
        p3->addResource(Resource::WOOL);
        p3->addResource(Resource::BRICK);
        p3->addResource(Resource::STONE);
        p3->addResource(Resource::WHEAT);
    }

    // Trying to place a settlement where one already exists
    try {
        game.placeSettlement(0);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    game.upgradeSettlement(0); //Michael places a city.

    //Trying to upgrade a city again.
    try {
        game.upgradeSettlement(0); 
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    game.endTurn(); //Robert's turn.

    // Trying to upgrade someone else's settlement.
    try {
        game.upgradeSettlement(16);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Trying to place a road where one already exists
    try {
        game.placeRoad(0, 8);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Trying to place a road where you shouldn't
    try {
        game.placeRoad(1, 8);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Trying to build a settlement too close to another.
    try {
        game.placeSettlement(10);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Trying to build a settlement when there are no roads connecting to it.
    try {
        game.placeSettlement(20);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    //Development Card Logic Tests
    //It's still Robert's turn....
    game.buyDevelopmentCard();
    
    //Now Robert should have insufficient resources to buy a Development Card.
    try {
        game.buyDevelopmentCard();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
}

void testDevCard() {
    // Create players
    Player* p1 = new Player("Michael");
    Player* p2 = new Player("Robert");
    Player* p3 = new Player("Edward");

    // Initialize game
    Catan game(p1, p2, p3);

    p1->addDevCard(DevCardType::KNIGHT);
    p1->addDevCard(DevCardType::KNIGHT);
    //Let's say Robert has 3 knights.
    p2->addDevCard(DevCardType::KNIGHT);
    p2->addDevCard(DevCardType::KNIGHT);

    game.checkBiggestArmyCard(); //No one has 3 knights yet.
    std::cout << "Michael has " << p1->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "Robert has " << p2->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "----" << std::endl;
    p2->addDevCard(DevCardType::KNIGHT);
    game.checkBiggestArmyCard(); //Robert has 3 knights, and should be awarded the biggest army card.
    std::cout << "Michael has " << p1->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "Robert has " << p2->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "----" << std::endl;

    p1->addDevCard(DevCardType::KNIGHT);
    game.checkBiggestArmyCard(); //Robert should lose the biggest army card since now he and another player both have 3 knights.
    std::cout << "Michael has " << p1->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "Robert has " << p2->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "----" << std::endl;

    p1->addDevCard(DevCardType::KNIGHT);
    game.checkBiggestArmyCard(); // Michael should now get it.
    std::cout << "Michael has " << p1->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "Robert has " << p2->getVictoryPoints() << " victory points." << std::endl;
    std::cout << "----" << std::endl;
    
    for(int i = 0; i < 5; i++){
        p1->addResource(Resource::WOOD);
        p1->addResource(Resource::WOOL);
        p1->addResource(Resource::BRICK);
        p1->addResource(Resource::STONE);
        p1->addResource(Resource::WHEAT);

        p2->addResource(Resource::WOOD);
        p2->addResource(Resource::WOOL);
        p2->addResource(Resource::BRICK);
        p2->addResource(Resource::STONE);
        p2->addResource(Resource::WHEAT);

        p3->addResource(Resource::WOOD);
        p3->addResource(Resource::WOOL);
        p3->addResource(Resource::BRICK);
        p3->addResource(Resource::STONE);
        p3->addResource(Resource::WHEAT);
    }

    p1->addDevCard(DevCardType::MONOPOLY);
    game.useMonopolyCard(Resource::WOOD);
    p1->printResources();
    p2->printResources();
    p3->printResources();

    //Michael does not own the card.
    try {
        game.useYearOfPlentyCard(Resource::WOOD,Resource::BRICK);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    p1->addDevCard(DevCardType::YEAR_OF_PLENTY);
    game.useYearOfPlentyCard(Resource::WOOD,Resource::WOOL);
    p1->printResources();
    //Michael will not have that card anymore.
    try {
        game.useYearOfPlentyCard(Resource::WOOD,Resource::BRICK);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


}

void testMiscellaneous() {
    // Create players
    Player* p1 = new Player("Michael");
    Player* p2 = new Player("Robert");
    Player* p3 = new Player("Edward");

    // Initialize game
    Catan game(p1, p2, p3);

    for(int i = 0; i < 1; i++){
        p1->addResource(Resource::WOOD);
        p1->addResource(Resource::WOOL);
        p1->addResource(Resource::BRICK);
        p1->addResource(Resource::STONE);
        p1->addResource(Resource::WHEAT);

        p2->addResource(Resource::WOOD);
        p2->addResource(Resource::WOOL);
        p2->addResource(Resource::BRICK);
        p2->addResource(Resource::STONE);
        p2->addResource(Resource::WHEAT);

        p3->addResource(Resource::WOOD);
        p3->addResource(Resource::WOOL);
        p3->addResource(Resource::BRICK);
        p3->addResource(Resource::STONE);
        p3->addResource(Resource::WHEAT);
    }
 
    // Trying to trade yourself
    try {
        game.tradeResource(p1 ,Resource::WOOD,3,Resource::BRICK,3);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    // Trying to trade insufficient resource
    try {
        game.tradeResource(p2 ,Resource::WOOD,5,Resource::BRICK,5);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
   p1->printResources();
    p2->printResources();
    game.tradeResource(p2 ,Resource::WOOD,1,Resource::BRICK,1);
    std::cout << "----" << std::endl;
    p1->printResources();
    p2->printResources();

    // Trying to trade insufficient dev cards
    try {
        game.tradeDevCards(p2 ,DevCardType::KNIGHT,1,DevCardType::YEAR_OF_PLENTY,1);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "----" << std::endl;
    p1->addDevCard(DevCardType::YEAR_OF_PLENTY);
    game.tradeDevCards(p2,DevCardType::YEAR_OF_PLENTY,1,DevCardType::YEAR_OF_PLENTY,0);
    game.endTurn();
    game.useYearOfPlentyCard(Resource::WOOD,Resource::WOOD);

    // No winner at this time.
    game.checkWinner();
    
    std::cout << "------" << std::endl;
    for(int j = 0; j < 10; j++){
        p1->addVictoryPoint();
    }
    // No winner at this time.
    game.checkWinner();
}

int main() {
    testBoardPlacements();
    testDevCard();
    testMiscellaneous();
    return 0;
}