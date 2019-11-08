#include "CommandLineArgument.h"
#include "Game.h"
#include "Deck.h"
#include "Random.h"
#include "Display.h"
#include "Player.h"
#include "Random.h"
Game::Game(CommandLineArgument cla):deck(cla.getDeckFileName()), rules(cla.getRulesFileName()), random(cla.getSeed()) {

}
void Game::play() {
    askForPlayerInfo();
    dealInitialHand();
    flipOneCardToDiscard();
    chooseStartingPlayer();
    
    /*
    while(!winner){

        currPlayerTurn = (currPlayerTurn + 1) % numPlayers
    }
    */
}
void Game::askForPlayerInfo() {
    numPlayers = display.getNumPlayers();
    for (int currPlayer = 1; currPlayer < numPlayers+1; currPlayer++) {
        std::string playerName = display.getPlayerName(&currPlayer);
        players.push_back(Player(playerName));
    }
}

void Game::dealInitialHand() {
    int maxHandSize = rules.getStartingHandSize();
    for (int round = 0; round < maxHandSize; round++) {
        for (int currPlayer = 0; currPlayer < numPlayers; ++currPlayer) {
            if(deck.getSize() == 1){
                break;
            }
            else{ //Player draws a card
                players[currPlayer].addCardToHand(deck.getCard(random));
            }
        }
    }
}

void Game::flipOneCardToDiscard() {
    discard.add(deck.getCard(random));
}

void Game::chooseStartingPlayer() {
    int playerIndex = random.getNum(0,numPlayers);
    currPlayerTurn = &players.at(playerIndex);
}



