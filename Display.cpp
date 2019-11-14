#include "Display.h"
#include <iostream>
#include "InputVal.h"
#include <string>
#include "DiscardPile.h"
#include "Move.h"
#include "Game.h"
Display::Display() {

}

int Display::getNumPlayers() const {
    int numPlayers;
    std::string prompt = "Enter the number of players in the game: ";
    getInput(prompt, &numPlayers);
    return numPlayers;
}

std::string Display::getPlayerName(int* playerNum) const {
    std::string playerName;
    std::string prompt = "Player " + std::to_string(*playerNum) + " enter your name: ";
    getInput(prompt,&playerName);
    return playerName;
}

void Display::showOtherPlayersHands(const std::vector<Player> &players, const Player *currPlayerTurn) const {
    // only display the other players
    const Player& currPlayer = *currPlayerTurn;
    for(const Player& player : players){
        if(!(player.getName() == currPlayer.getName())) {
            std::cout << player.getName() << ": " << std::flush;
            showCurrPlayerHand(player);
            std::cout << std::endl;
        }
    }
}

void Display::showCurrPlayerHand(const Player &player) const {
    std::vector<Card> playerHand = player.getHand();
    for(const auto& card:playerHand){
        std::cout<< card.getColor() << " " << card.getValue() << "," << std::flush;
    }
}

void Display::showDiscardPile(const DiscardPile &discardPile) {
     Card topCard = discardPile.getTopCard();
     std::cout << "Top of discard pile: " << topCard.getColor() << " " <<topCard.getValue() << std::endl;
}

void Display::showYourHand(const Player &player) const {
    std::cout<< "Your hand: "<<std::flush;
    showCurrPlayerHand(player);
    std::cout<<std::endl;
}

void Display::getMove(Player &player) const {
    //std::string playerName = player.getName();
    std::cout<<player.getName()<<", enter your move or h for help: " << std::flush;
    std::string userInput;
    std::getline(std::cin,userInput);
    player.setMove(Move(userInput));
    //list all possible options for move and figure out what container to use.
}

void Display::showUnknownCommand() const {
    std::cout << "Unknown command entered.\n"
                 "    - play card_color card_value [uno]\n"
                 "    - draw\n"
                 "    - uno player_name\n"
                 "    - skip\n"
                 "    - quit\n"
                 "    - help\n" << std::endl;
}

void Display::showCardNotInHand(const Card &card) const {
    std::cout<<"You can't play a "<< card.getColor()<< " " << card.getValue() << " because you aren't holding one."<<std::endl;
}

void Display::showCannotPutInDiscard(const Card &card) const {
    std::cout<<"Your card must match either the color or value of the top card on the discard pile which is "<< card.getColor()<< " " << card.getValue() << "." <<std::endl;
}

void Display::showReneging(const std::string &move) const {
    std::cout<<"You can't play a " << move << " right now." <<std::endl;

}

void Display::showCard(const Card &card) const {
    std::cout<<card.getColor()<< " " << card.getValue() <<std::flush;
}

void Display::showplayCard(Game game) const {
    std::string playerName = game.getCurrPlayer().getName();
    Card cardPlayed = game.getCurrPlayer().getCardPlayedFromHand();
    std::cout<<playerName<<" played ";
    showCard(cardPlayed);
    std::cout<<"."<<std::endl;
}

void Display::showMaxCardDrawn() const {
    std::cout<<"You have already drawn the maximum number of cards this round." << std::endl;
}

void Display::showDiscardPileEmpty() const {
    std::cout <<"Dicard pile is empty" << std::endl;
}

void Display::showCannotSkip(const int& numCardToDraw) const {
    std::cout<<"You cannot pass until you either play a card or draw at least "<< numCardToDraw <<" more cards."<<std::endl;

}

void Display::showHelp() const{
    std::cout<<"    - play card_color card_value [uno]\n"
               "    - draw\n"
               "    - uno player_name\n"
               "    - skip\n"
               "    - quit\n"
               "    - help\n" << std::endl;
}

void Display::showQuit(const std::vector<Player> players) const {
    int minScore = players.at(1).getScore();
    Player winner = players.at(1);
    for (const auto& player:players){
        if(minScore < player.getScore()){
            winner = player;
        }
    }
    std::cout<<winner.getName()<< " won the game.\n" <<std::endl;

    std::cout<<"==== Leader Board ====" <<std::endl;
    int numPlayers = players.size();
    for(int i = 0;i<numPlayers;i++){
        std::cout<< i <<".) "<< players.at(i).getName()<<" : " << players.at(i).getScore() <<std::endl;
    }

}

void Display::showCannotCallUno() const {
    std::cout<<"You can't call UNO unless playing your second to last card."<<std::endl;
}

void Display::showUnoPlayerNotValid(const std::string& name) const {
    std::cout<<name<<" is not in this game or is current player."<<std::endl;
}

void Display::showUnoPlayerMoreThanOneCard(const Player &player) const {
    std::cout<<"You can't call UNO on " << player.getName()<<" because they have more than 1 card in their hand"<<std::endl;

}

void Display::showUnPlayeCalledUno(const Player &player) const {
    std::cout<<player.getName()<<" called out uno already"<<std::endl;
}

void Display::showUnoCalledSuccessful(const Player &player) const {
    std::cout<< "You called out "<< player.getName()<< " for not saying UNO." <<std::endl;
}


/*
void Display::getPlayerInfo() {
    int numPlayers;
    std::string playerName;
    std::string prompt = "Enter the number of players in the game: ";
    getInput(prompt, &numPlayers);
    for(int currPlayer = 0;currPlayer<numPlayers;currPlayer++){
        std::string prompt = ""
        getInput(prompt)
    }
    std::cout << numPlayers <<std::endl;

}
*/