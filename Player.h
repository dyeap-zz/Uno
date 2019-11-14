//
// Created by Danny Yeap on 11/6/19.
//

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H
#include <string>
#include "Card.h"
#include "Move.h"
#include "Deck.h"
#include <vector>
class Game;
class Player{
public:
    Player(const std::string& name);
    void addCardToHand(Card card);
    std::string getName() const;
    std::vector<Card> getHand() const;
    void setMove(Move move);
    Move getMove()const;
    Card getCardPlayed() const;
    bool unoCalled()const;
    void processMoveString();
    std::string getAction()const;
    void drawInitialCard(Deck& deck);
    void processPlayMove();
    int getNumCardsDrawnOnThisTurn()const;
    Card getLastCardDrawn()const;
    bool drawCard(Game& game);
    void turnEnding();
    bool getEndTurn()const;
    std::vector<std::string> getVectorMove()const;
    void setCardPlayedIndex(const int& index);
    Card getCardPlayedFromHand()const;
    void playCard(Game& game);
    bool operator ==(const Player& otherPlayer);
    void setEndTurn(const bool& end);
    void completelyEndTurn();
private:
    std::string name;
    std::vector<Card> hand;
    Move move;
    std::vector<std::string> vectorMove;
    // used for card played
    Card cardPlayed;
    int cardPlayedIndex;
    bool uno = 0;
    // used for reneging
    int numCardsDrawnOnThisTurn = 0;
    bool endTurn = false;
};
#endif //UNO_PLAYER_H
