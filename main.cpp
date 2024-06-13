
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

int main() {

    //The logic of catan is fully intergrated into the 'Catan' class, that 
    //means we could easily implement a UI and build an actual game.
    //Note that I have yet to implement the longest path card since it wasn't required
    //and didn't have time to but in order to add it we must run a longest path algorithm which is 
    //rather difficult compared to shortest path.
    Player* p1 = new Player("Michael");
    Player* p2 = new Player("Robert");
    Player* p3 = new Player("Edward");

    Catan board(p1,p2,p3);
    
    //Pre-game, each players places 2 settlements and 2 roads for free.
    board.placeFreeSettlement(p1,31);
    board.placeFreeSettlement(p1,12);
    board.placeFreeRoad(p1,31,32);
    board.placeFreeRoad(p1,32,42);

    board.placeFreeSettlement(p2,17);
    board.placeFreeSettlement(p2,39);
    board.placeFreeRoad(p2,39,40);
    board.placeFreeRoad(p2,17,18);

    board.placeFreeSettlement(p3,36);
    board.placeFreeSettlement(p3,23);
    board.placeFreeRoad(p3,36,35);
    board.placeFreeRoad(p3,23,13);

    //Turns-based Michael starts.
    board.rollDice();
    board.endTurn();
    //Now its Robert's turn.
    board.rollDice();
    board.endTurn();

    p1->printResources();
    p2->printResources();
    p3->printResources();

    delete p1;
    delete p2;
    delete p3;
    board.deleteBoard();

    return 0;
}
