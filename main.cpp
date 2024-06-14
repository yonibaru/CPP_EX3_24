
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Types.hpp"

int main() {

    //The logic of catan is fully intergrated into the 'Catan' class, that 
    //means we could easily implement a UI and build an actual game. Missing features that weren't required but 
    //ARE requried to play the full game:
    // * Trades with Ports - could be easily supported in my code.
    // * Longest Path - not trivial, we need to run a longest path algorithm at the end of each turn
    //   which is NOT polynomial.
    // * Robber -

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


    board.checkWinner(); //Iterates over the players, check if theres a player with 10 or more victory points.

    delete p1;
    delete p2;
    delete p3;
    board.deleteBoard();

    return 0;
}
