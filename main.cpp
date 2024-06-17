
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

//SMALL DEMO:

int main() {

    //This section can be mainly used to show how rollDice() works.
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

    p1->printResources();
    p2->printResources();
    p3->printResources();
    //Turns-based game starts: Michael goes first.
    board.rollDice();
    board.endTurn();
    //Now its Robert's turn.
    board.rollDice();
    board.endTurn();
    //Now its Edwards's turn.
    board.rollDice();
    board.endTurn();
    //We can see the accurate resources each player would have.


    p1->printResources();
    p2->printResources();
    p3->printResources();


    board.checkWinner(); //Iterates over the players, check if theres a player with 10 or more victory points.


    //No need to free memory, we have a destructor in place.
    return 0;
}
