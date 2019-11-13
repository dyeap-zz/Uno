#include "CommandLineArgument.h"
#include "Game.h"
#include "Deck.h"
#include "Random.h"
#include "Display.h"
#include "Player.h"
#include "Random.h"
#include <sstream>
#include <string>
#include <iostream>
Game::Game(CommandLineArgument cla):deck(cla.getDeckFileName()), rules(cla.getRulesFileName()), random(cla.getSeed()) {
    std::string s1 = "play";
    std::string s2 = "z";
    std::size_t index = s1.find(s2);
    if(s1.find(s2)){
        std::cout<< "Yes" <<std::endl;
    }
    else{
        std::cout<< "No" <<std::endl;
    }
}
void Game::play() {
    askForPlayerInfo();
    shuffleDeck();
    dealInitialHand();
    flipOneCardToDiscard();
    chooseStartingPlayer();
    while(!winner){
        startGame();
        display.getMove(*currPlayerTurn);
        processMove();
        //See if there's a winner
        // EndPlayerTurn
        //currPlayerTurn = (currPlayerTurn + 1) % numPlayers
    }

}

void Game::shuffleDeck() {
    deck.shuffle(random.getGenerator());
}

void Game::startGame() {
    display.showOtherPlayersHands(players,currPlayerTurn);
    display.showDiscardPile(discard);
    display.showYourHand(*currPlayerTurn);
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
                players[currPlayer].drawInitialCard(deck);
                //players[currPlayer].addCardToHand(deck.draw());
            }
        }
    }
}

void Game::flipOneCardToDiscard() {
    discard.add(deck.draw()); //Need to convert to use std::shuffle and then draw cards from the back of the vector
}

void Game::chooseStartingPlayer() {
    int playerIndex = random.getNum(0,numPlayers);
    currPlayerTurn = &players.at(playerIndex);
}

void Game::processMove() {
    if (validMove(*currPlayerTurn)){
        // Break up move into different parts and check what the first move is
        // Move everything into  player class
        // use if loop and make functions called process
        (*currPlayerTurn).processMoveString();
        std::string action = (*currPlayerTurn).getAction();
        if(action == "play"){
            // at this point need to double check that
            std::vector<std::string> currVectorMove = currPlayerTurn->getVectorMove();
            if (!validPlayInput()){
                display.showUnknownCommand();
            }
           processPlay();

        }
        else if(action  == "draw"){
            processDraw();
        }
        else if(action == "skip"){
            processSkip();
        }
        else if(action == "quit"){
            //processQuit();
        }
        else if(action == "help"){

        }
        else if(action == "uno"){

        }
    }
    else{
        // display Unknown command entered. and then show the help display from the help command.
        display.showUnknownCommand();
    }
}

bool Game::validMove(const Player& player) const {
    //std::vector<std::string> validMoves = move.getValidMoves();
    Move currMove = player.getMove();
    std::stringstream ss(currMove.getName());
    std::string move;
    ss >> move;
    for (const auto& goodMove:validMoves){
        if (move == goodMove){
            return true;
        }
    }
    return false;
}

void Game::processPlay() {
    // either good input of bad input. Run through all bad input if not bad then it must be good
    // Make the card that was played by the player. Figure out someway that uno was payed
    // check it play command is valid;
    // Check that there is appropriate number of data after play
    // Card is equal as long the move has part of substring are equal
    // only have to check that third on is number and if the fourth one is uno/unosubstr
    // make sure size of vector can only be between

    (*currPlayerTurn).processPlayMove();
    if(cardNotInHand(*currPlayerTurn)){
        //figure out what you need to show
    }
    else if (cannotPutOnTopOfDiscardPile()){

    }
    else if (mustPlayLastCardDrawn(*currPlayerTurn)){

    }
    else{ // good input play the card

    }
}

bool Game::cannotPutOnTopOfDiscardPile() const {
    Card cardPlayed = currPlayerTurn->getCardPlayed();
    Card topCard = discard.getTopCard();
    if (!(cardPlayed == topCard)){
        return false;
    }
    return true;
}

bool Game::cardNotInHand(const Player& player) { // Need the person's hand and the card played
    // iterate through all card in player hand and see if it's there
    Card cardPlayed =  player.getCardPlayed();
    for (const auto& card:player.getHand()){
        if(cardPlayed == card) {
            return false;
        }
    }
    return true;
}

bool Game::mustPlayLastCardDrawn(const Player& player) const {
    // check if player must player last card drawn from rules
    // check if player drew a card last turn
    // check if last card drawn is the cardplayed
    // if any card then return false
    int numCardsDrawn = player.getNumCardsDrawnOnThisTurn();
    Card cardPlayed = player.getCardPlayed();
    Card LastCardDrawn = player.getLastCardDrawn();
    if(rules.getReneging() == "Last Drawn" && numCardsDrawn > 0 && !(cardPlayed == LastCardDrawn)){
        return true;
    }
    return false;
}

void Game::processDraw() {
    // Try to draw card. If have not reached limit then you can draw the card.
    Player currPlayer = *currPlayerTurn;
    if(currPlayer.drawCard(deck,rules.getDrawLimit())){
        // successfull drew card display
    }
    else{
        // could not draw card due to max limit
    }
}

void Game::processSkip() {
    // do nothing if you can skip
    //There are no more cards left to draw and you cannot play any cards
    //Or you have drawn the maximum amount of cards for a turn and you are not required to play a card
    int cardsDrawn = currPlayerTurn->getNumCardsDrawnOnThisTurn();
    if((deck.isEmpty() && cannotPlayAnyCards(*currPlayerTurn)) || (cardsDrawn == rules.getDrawLimit() && !rules.getMustPlayCardEachTurn()) ){
        // Allowed to skip
    }
    else{
        // cannot skip
    }

}

bool Game::cannotPlayAnyCards(const Player& player) const {
    for (auto& card:player.getHand()){
        if(card == discard.getTopCard()){
            return false;
        }
    }
    return true;
}

bool Game::validPlayInput() const {

    return false;
}




