#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#include "vertex.hpp"
#include "edge.hpp"
#include "tile.hpp"
#include "board.hpp"
#include "player.hpp"
#include "person.hpp"
#include "gameLogic.hpp"
#include "developmentCard.hpp"
#include "deck.hpp"

#define KNIGHT "Knight"
#define ROAD_BUILDING "RoadBuilding"
#define YEAR_OF_PLENTY "YearOfPlenty"
#define MONOPOLY "Monopoly"
#define VICTORY_POINT "VictoryPoint"

using namespace std;

int main(){
    player p1("yair", 25);
    player p2("david", 19);
    player p3("shlomo", 20);
    
    vector<player> p = {p1, p2, p3};
    gameLogic g1(p);
    g1.chooseFirstPlayer();
    board b;
    
    deck d;
    cout << endl;
 
    //First turn of the game - each player places a settlement and a road on the board
    p[0].placeSettelemnt(b, b.get_board()[0].getVertexes()[3], 1);// set v31 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b, b.get_board()[0].getEdges()[2], 1);// set e2 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;
    //********* second player try to place a settlement and a road on the same vertex and edge **********
    p[1].placeSettelemnt(b,b.get_board()[1].getVertexes()[4], 1);// set v31 as a settlement, but it is already occupied
    p[1].getResources();
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[0].getEdges()[2], 1);// set e2 as a settlement, but it is already occupied
    p[1].getRoads();
    p[1].getNumberOfPoints();
    //********* second player place a settlement and a road on another vertex and edge **********
    cout << endl;
    p[1].placeSettelemnt(b,b.get_board()[12].getVertexes()[1], 1);// set v43 as a settlement
    p[1].getResources();
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[12].getEdges()[3], 1);// set e49 as a settlement
    p[1].getRoads();
    p[1].getNumberOfPoints();
    cout << endl;

    p[2].placeSettelemnt(b,b.get_board()[10].getVertexes()[0], 1);// set v36 as a settlement
    p[2].getResources();
    p[2].getSettlements();
    p[2].placeRoad(b,b.get_board()[10].getEdges()[4], 1);// set e30 as a settlement
    p[2].getRoads();
    p[2].getNumberOfPoints();
    cout << endl;
    //second turn of the game - each player places a settlement and a road on the board
    p[0].placeSettelemnt(b,b.get_board()[7].getVertexes()[2], 1);// set v46 as a settlement
    p[0].getResources();
    p[0].getSettlements();
    p[0].placeRoad(b,b.get_board()[7].getEdges()[2], 1);// set e32 as a road
    p[0].getRoads();
    p[0].getNumberOfPoints();
    cout << endl;

    p[1].placeSettelemnt(b,b.get_board()[15].getVertexes()[0], 1);// set v12 as a settlement
    p[1].getResources();
    p[1].getSettlements();
    p[1].placeRoad(b,b.get_board()[15].getEdges()[4], 1);// set e48 as a road
    p[1].getRoads();
    p[1].getNumberOfPoints();
    cout << endl;

    p[2].placeSettelemnt(b,b.get_board()[17].getVertexes()[5], 1);// set v41 as a settlement
    p[2].getResources();
    p[2].getSettlements();
    p[2].placeRoad(b,b.get_board()[17].getEdges()[4], 1);// set e54 as a road
    p[2].getRoads();
    p[2].getNumberOfPoints();
    cout << endl;

    // The game continues with the rest of the turns, each player roll the dice and do the actions that he can do (place a settlement, place a road, buy a development card, trade, end turn)
    
    srand(time(0)); // ensure that the random number will be different each time

    p[0].rollDice(b, g1); // player 1 roll the dice, the turn is now of player 1
    cout << endl;

    //********** player 1 try to trade with player 2 **********
    p[0].getResources();
    cout << endl;
    p[1].getResources();
    cout << endl;
    p[0].trade(p[1], 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);// player 1 ask, 1 wood for 1 sheep
    cout << endl;
    p[0].getResources();
    cout << endl;
    p[1].getResources();
    cout << endl;

    //********** player 1 try to buy a development card **********
    cout << "Number of development: " << d.getDeckSize() << endl;
    p[0].getResources();
    cout << endl;
    p[0].buyDevelopmentCard(d, g1);
    cout << "Number of development: " << d.getDeckSize() << endl;
    p[0].printDevelopmentCards();
    cout << endl;
    p[0].playDevelopmentCard(g1, d, KNIGHT);
    cout << "Number of development: " << d.getDeckSize() << endl;
    cout << p[0].getKnightCards() << endl;
    cout << endl;

    p[0].getResources();
    p[1].getResources();
    cout << endl;
    // ********** player 1 try to play all the development cards **********
    p[0].playDevelopmentCard(g1, d, ROAD_BUILDING);
    p[0].playDevelopmentCard(g1, d, YEAR_OF_PLENTY);
    p[0].playDevelopmentCard(g1, d, MONOPOLY);
    p[0].playDevelopmentCard(g1, d, VICTORY_POINT);
    cout << endl;

    p[0].getResources();
    p[1].getResources();
    cout << endl;

    p[0].printDevelopmentCards();
    p[0].getNumberOfPoints();
    cout << endl;

    p[0].endTurn(g1); // player 1 end his turn

    p[1].rollDice(b, g1); // player 2 roll the dice, the turn is now of player 2
    p[1].endTurn(g1); // player 2 end his turn

    p[2].rollDice(b, g1); // player 3 roll the dice, the turn is now of player 3

    //********** player 3 try to trade with player 1 **********
    p[2].getResources();
    cout << endl;
    p[0].getResources();
    cout << endl;
    p[2].trade(p[0], 1, 1, 0, 0, 0, 0, 0, 1, 0, 0);// player 2 ask, 1 wood and 1 iron for 1 wheat
    cout << endl;
    p[0].getResources();
    cout << endl;
    p[2].getResources();
    cout << endl;

    cout << "The score after the first round, that all the player rolled the dices:" << endl;
    p[0].getNumberOfPoints();
    p[1].getNumberOfPoints();
    p[2].getNumberOfPoints();
    cout << endl;

    cout << g1.gameFhinished() << endl;

    return 0;
}